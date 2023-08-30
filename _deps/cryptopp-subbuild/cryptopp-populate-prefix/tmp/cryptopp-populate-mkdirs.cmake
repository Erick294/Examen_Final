# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/workspace/Examen_Final/_deps/cryptopp-cmake-build/cryptopp"
  "/workspace/Examen_Final/_deps/cryptopp-build"
  "/workspace/Examen_Final/_deps/cryptopp-subbuild/cryptopp-populate-prefix"
  "/workspace/Examen_Final/_deps/cryptopp-subbuild/cryptopp-populate-prefix/tmp"
  "/workspace/Examen_Final/_deps/cryptopp-subbuild/cryptopp-populate-prefix/src/cryptopp-populate-stamp"
  "/workspace/Examen_Final/_deps/cryptopp-subbuild/cryptopp-populate-prefix/src"
  "/workspace/Examen_Final/_deps/cryptopp-subbuild/cryptopp-populate-prefix/src/cryptopp-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/workspace/Examen_Final/_deps/cryptopp-subbuild/cryptopp-populate-prefix/src/cryptopp-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/workspace/Examen_Final/_deps/cryptopp-subbuild/cryptopp-populate-prefix/src/cryptopp-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
