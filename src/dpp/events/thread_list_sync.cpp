/************************************************************************************
 *
 * D++, A Lightweight C++ library for Discord
 *
 * Copyright 2021 Craig Edwards and D++ contributors 
 * (https://github.com/brainboxdotcc/DPP/graphs/contributors)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ************************************************************************************/
#include <dpp/discord.h>
#include <dpp/event.h>
#include <string>
#include <iostream>
#include <fstream>
#include <dpp/discordclient.h>
#include <dpp/discordevents.h>
#include <dpp/discord.h>
#include <dpp/cache.h>
#include <dpp/stringops.h>
#include <dpp/nlohmann/json.hpp>
#include <dpp/fmt/format.h>

using json = nlohmann::json;

namespace dpp { namespace events {

using namespace dpp;
void thread_list_sync::handle(discord_client* client, json& j, const std::string& raw) {
	json& d = j["d"];

	dpp::guild* g = dpp::find_guild(SnowflakeNotNull(&d, "guild_id"));
	if (g) {
		/** Store thread IDs*/
		if (d.find("threads") != d.end()) {
			for (auto& t : d["threads"]) {
				g->threads.push_back(SnowflakeNotNull(&t, "id"));
			}
		}
		if (!client->creator->dispatch.thread_list_sync.empty()) {
			dpp::thread_list_sync_t tls(client, raw);
			if (d.find("threads") != d.end()) {
				for (auto& t : d["threads"]) {
					tls.threads.push_back(thread().fill_from_json(&t));
				}
			}
			if (d.find("members") != d.end()) {
				for (auto& tm : d["members"]) {
					tls.members.push_back(thread_member().fill_from_json(&tm));
				}
			}
			call_event(client->creator->dispatch.thread_list_sync, tls);
		}
	}
}
}};
