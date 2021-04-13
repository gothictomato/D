#pragma once

#include <dpp/discord.h>
#include <dpp/json_fwd.hpp>

namespace dpp {

/**
 * @brief Bit mask flags relating to voice states
 */
enum voicestate_flags {
	vs_deaf		=	0b00000001,
	vs_mute		=	0b00000010,
	vs_self_mute	=	0b00000100,
	vs_self_deaf	=	0b00001000,
	vs_self_stream	=	0b00010000,
	vs_self_video	=	0b00100000,
	vs_supress	=	0b01000000
};

/**
 * @brief Represents the voice state of a user on a guild
 * We don't cache these right now, but may do when we implement voice
 */
class voicestate {
public:
	snowflake       guild_id;       //< Optional: the guild id this voice state is for
	snowflake       channel_id;     //< the channel id this user is connected to (may be empty)
	snowflake       user_id;        //< the user id this voice state is for
	std::string     session_id;     //< the session id for this voice state
	uint8_t		flags;		//< Voice state flags

	/**
	 * @brief Construct a new voicestate object
	 */
	voicestate();

	/**
	 * @brief Destroy the voicestate object
	 */
	~voicestate();

	/**
	 * @brief Fill voicestate object from json data
	 * 
	 * @param j JSON data to fill from
	 * @return voicestate& Reference to self
	 */
	voicestate& fill_from_json(nlohmann::json* j);

	/**
	 * @brief Build json representation of the object
	 * 
	 * @return std::string JSON string
	 */
	std::string build_json() const;

	/// Return true if user is deafened
	bool is_deaf() const;
	/// Return true if user is muted
	bool is_mute() const;
	/// Return true if user muted themselves
	bool is_self_mute() const;
	/// Return true if user deafened themselves
	bool is_self_deaf() const;
	/// Return true if the user is streamig
	bool self_stream() const;
	/// Return true if the user is in video
	bool self_video() const;
	/// Return true if user is surpressed.
	/// "HELP HELP I'M BEING SUPRESSED!"
	bool is_supressed() const;
};

/** A container of voicestates */
typedef std::unordered_map<std::string, voicestate> voicestate_map;

};