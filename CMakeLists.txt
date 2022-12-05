cmake_minimum_required(VERSION 3.16.2)
project(MonoScript)

set(CMAKE_CXX_STANDARD 20)

add_library(MonoScript STATIC MonoScript.cxx)

set(MONO_SCRIPT_CROSS ON)

target_include_directories(MonoScript PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)
target_include_directories(MonoScript PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/libs/mono)
target_include_directories(MonoScript PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/libs/mono/mono/eglib)
target_include_directories(MonoScript PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/libs)
target_include_directories(MonoScript PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/MonoScript/Mini)
target_include_directories(MonoScript PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/libs/mono)

add_subdirectory(cmake)

target_link_libraries(MonoScript MonoScriptLibrary)
