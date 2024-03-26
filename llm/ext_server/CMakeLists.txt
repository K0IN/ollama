
# set(TARGET ext_server)
# option(LLAMA_SERVER_VERBOSE "Build verbose logging option for Server" ON)
# if (WIN32)
#     add_library(${TARGET} SHARED ext_server.cpp ../llama.cpp/llama.cpp)
# else()
#     add_library(${TARGET} STATIC ext_server.cpp ../llama.cpp/llama.cpp)
# endif()
# target_compile_features(${TARGET} PRIVATE cxx_std_11)
# target_compile_definitions(${TARGET} PUBLIC LLAMA_SERVER_LIBRARY=1)
# target_link_libraries(${TARGET} PRIVATE ggml llava common )
# set_target_properties(${TARGET} PROPERTIES POSITION_INDEPENDENT_CODE ON)
# target_compile_definitions(${TARGET} PRIVATE SERVER_VERBOSE=$<BOOL:${LLAMA_SERVER_VERBOSE}>)
# install(TARGETS ext_server LIBRARY)
# 
# if (CUDAToolkit_FOUND)
#     target_include_directories(${TARGET} PRIVATE ${CMAKE_CUDA_TOOLKIT_INCLUDE_DIRECTORIES})
#     if (WIN32)
#         target_link_libraries(${TARGET} PRIVATE nvml)
#     endif()
# endif()


cmake_minimum_required(VERSION 3.11.0)
set(TARGET ext_server)

project(${TARGET} VERSION 0.1.0)

include(CTest)
enable_testing()

add_library(${TARGET} STATIC main.cpp)


set_property(TARGET ${TARGET} PROPERTY CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
  llama
  GIT_REPOSITORY https://github.com/ggerganov/llama.cpp.git
  GIT_TAG master-c9c74b4
  GIT_SUBMODULES ""
  CMAKE_ARGS
    -DCMAKE_BUILD_TYPE=Release
    -DLLAMA_STATIC=ON  # Static linking
    -DLLAMA_AVX=ON     # Enable AVX
    -DLLAMA_AVX2=ON    # Enable AVX2
    -DLLAMA_AVX512=ON  # Enable AVX512
    -DLLAMA_LTO=ON     # Enable link-time optimization
    -DLLAMA_NATIVE=ON  # Enable native CPU optimizations
    -LLAMA_CUDA=ON     # Enable CUDA support
    # Additional options go here
)

FetchContent_MakeAvailable(llama)

target_include_directories(${TARGET} PRIVATE ${llama_SOURCE_DIR})
target_link_libraries(${TARGET} PRIVATE llama)

if (CUDAToolkit_FOUND)
    target_include_directories(${TARGET} PRIVATE ${CMAKE_CUDA_TOOLKIT_INCLUDE_DIRECTORIES})
    if (WIN32)
        target_link_libraries(${TARGET} PRIVATE nvml)
    endif()
endif()