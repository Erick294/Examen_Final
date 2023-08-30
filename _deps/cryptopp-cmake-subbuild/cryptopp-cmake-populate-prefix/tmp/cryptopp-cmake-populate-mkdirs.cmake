# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/workspace/Examen_Final/_deps/cryptopp-cmake-src"
  "/workspace/Examen_Final/_deps/cryptopp-cmake-build"
  "/workspace/Examen_Final/_deps/cryptopp-cmake-subbuild/cryptopp-cmake-populate-prefix"
  "/workspace/Examen_Final/_deps/cryptopp-cmake-subbuild/cryptopp-cmake-populate-prefix/tmp"
  "/workspace/Examen_Final/_deps/cryptopp-cmake-subbuild/cryptopp-cmake-populate-prefix/src/cryptopp-cmake-populate-stamp"
  "/workspace/Examen_Final/_deps/cryptopp-cmake-subbuild/cryptopp-cmake-populate-prefix/src"
  "/workspace/Examen_Final/_deps/cryptopp-cmake-subbuild/cryptopp-cmake-populate-prefix/src/cryptopp-cmake-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/workspace/Examen_Final/_deps/cryptopp-cmake-subbuild/cryptopp-cmake-populate-prefix/src/cryptopp-cmake-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/workspace/Examen_Final/_deps/cryptopp-cmake-subbuild/cryptopp-cmake-populate-prefix/src/cryptopp-cmake-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
