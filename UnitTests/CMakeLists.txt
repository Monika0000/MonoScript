cmake_minimum_required(VERSION 3.16)
project(MonoScriptTest)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../ ${CMAKE_CURRENT_BINARY_DIR}/MonoScript)

add_executable(MonoScriptTest main.cpp)

target_link_libraries(MonoScriptTest MonoScript)