include("/workspace/Examen_Final/cmake/CPM.cmake")
CPMAddPackage("GITHUB_REPOSITORY;fmtlib/fmt;GIT_TAG;10.0.0;EXCLUDE_FROM_ALL;YES;SYSTEM;YES;")
set(fmt_FOUND TRUE)