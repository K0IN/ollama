# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.22.1)

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(llama-populate NONE)


# Pass through things we've already detected in the main project to avoid
# paying the cost of redetecting them again in ExternalProject_Add()
set(GIT_EXECUTABLE [==[/usr/bin/git]==])
set(GIT_VERSION_STRING [==[2.34.1]==])
set_property(GLOBAL PROPERTY _CMAKE_FindGit_GIT_EXECUTABLE_VERSION
  [==[/usr/bin/git;2.34.1]==]
)


include(ExternalProject)
ExternalProject_Add(llama-populate
                     "UPDATE_DISCONNECTED" "False" "GIT_REPOSITORY" "https://github.com/ggerganov/llama.cpp.git" "GIT_TAG" "master-c9c74b4" "GIT_SUBMODULES" "" "CMAKE_ARGS" "-DCMAKE_BUILD_TYPE=Release" "-DLLAMA_STATIC=ON" "-DLLAMA_AVX=ON" "-DLLAMA_AVX2=ON" "-DLLAMA_AVX512=ON" "-DLLAMA_LTO=ON" "-DLLAMA_NATIVE=ON" "-LLAMA_CUDA=ON"
                    SOURCE_DIR          "/mnt/e/src/ollama-2/llm/generate/build/_deps/llama-src"
                    BINARY_DIR          "/mnt/e/src/ollama-2/llm/generate/build/_deps/llama-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
                    USES_TERMINAL_DOWNLOAD  YES
                    USES_TERMINAL_UPDATE    YES
)


