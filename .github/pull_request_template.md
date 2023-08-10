# Contributing

When contributing to this repository, please do not feel intimidated! We welcome PRs from developers of all levels of experience and we were all new once.

## Pull Request Process

1. Pull requests should be made against the `dev` branch.
2. Ensure that the changed library can be built on your target system. Do not introduce any platform-
   specific code.
3. Ensure that all methods and functions you add are **fully documented** using doxygen style comments.
4. Test your commit! Make a simple single-file test bot to demonstrate the change, include this with the PR 
   as an attached file on a comment, so we can test and see how it works.
5. Ensure that you do not break any existing API calls without discussing on Discord first!
6. Be sure to follow the coding style guide (if you are not sure, match the code style of existing files
   including indent style etc).
7. Your PR must pass the CI actions before being allowed to be merged. Our PR actions check that the
   build will compile on various platforms before release and makes precompiled versions of the library.
8. Automated changes e.g. via grammarly or a static analysis tool will not usually be accepted into the code without proper thought out justification (by a human being, not an AI or an App) as to why the changes are required. Generally a PR should do more than fix a single spelling error for example as this just takes precious time for something which could be resolved a direct commit to the dev branch.
9. All contributors agree to the terms of the DCO (Developer Certificate of Origin) as listed below. This document is to protect you, and us, from any legal issues by making clear that code you contribute to this project becomes part the D++ project.

```
Version 1.1

Copyright (C) 2004, 2006 The Linux Foundation and its contributors.

Everyone is permitted to copy and distribute verbatim copies of this
license document, but changing it is not allowed.

By making a contribution to this project, I certify that:

(a) The contribution was created in whole or in part by me and I
    have the right to submit it under the open source license
    indicated in the file; or

(b) The contribution is based upon previous work that, to the best
    of my knowledge, is covered under an appropriate open source
    license and I have the right under that license to submit that
    work with modifications, whether created in whole or in part
    by me, under the same open source license (unless I am
    permitted to submit under a different license), as indicated
    in the file; or

(c) The contribution was provided directly to me by some other
    person who certified (a), (b) or (c) and I have not modified
    it.

(d) I understand and agree that this project and the contribution
    are public and that a record of the contribution (including all
    personal information I submit with it, including my sign-off) is
    maintained indefinitely and may be redistributed consistent with
    this project or the open source license(s) involved.
```
    