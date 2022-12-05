cmake_minimum_required(VERSION 3.16.2)
project(MonoScript)

enable_language(C ASM_MASM)

set(CMAKE_CXX_STANDARD 14)

set(MONO_SCRIPT_LIBRARY_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../libs/mono)
set(MONO_SCRIPT_CONFIG_PATH ${CMAKE_CURRENT_BINARY_DIR}/MonoScript)

add_subdirectory(zlib)

# ----------------------------------------------------------------------------------------------------------------------
include(Mini.cmake)

add_library(MonoScriptLibrary STATIC ${MONO_SCRIPT_UTILS_SOURCES})

if (WIN32)
    target_compile_definitions(MonoScriptLibrary PRIVATE HAVE_API_SUPPORT_WIN32_LOAD_LIBRARY)
    target_compile_definitions(MonoScriptLibrary PRIVATE HAVE_API_SUPPORT_WIN32_CONSOLE=1)
    target_compile_definitions(MonoScriptLibrary PRIVATE HAVE_API_SUPPORT_WIN32_GET_MODULE_HANDLE)

    if (MONO_SCRIPT_CROSS)
        target_compile_definitions(MonoScriptLibrary PRIVATE USED_CROSS_COMPILER_OFFSETS=1)
        target_compile_definitions(MonoScriptLibrary PRIVATE MONO_CROSS_COMPILE=1)
    endif()
endif()

target_include_directories(MonoScriptLibrary PUBLIC ${MONO_SCRIPT_CONFIG_PATH})
target_include_directories(MonoScriptLibrary PRIVATE ${MONO_SCRIPT_LIBRARY_PATH})

# ----------------------------------------------------------------------------------------------------------------------
list(APPEND MONO_SCRIPT_LIBRARY_LINK version)
list(APPEND MONO_SCRIPT_LIBRARY_LINK MonoScriptMini)
list(APPEND MONO_SCRIPT_LIBRARY_LINK Ws2_32)
list(APPEND MONO_SCRIPT_LIBRARY_LINK zlib)
list(APPEND MONO_SCRIPT_LIBRARY_LINK Winmm)
list(APPEND MONO_SCRIPT_LIBRARY_LINK Bcrypt)
# ----------------------------------------------------------------------------------------------------------------------
target_link_libraries(MonoScriptLibrary ${MONO_SCRIPT_LIBRARY_LINK})
target_include_directories(MonoScriptLibrary PRIVATE ${MONO_SCRIPT_LIBRARY_PATH}/mono)
target_include_directories(MonoScriptLibrary PRIVATE ${MONO_SCRIPT_LIBRARY_PATH})
target_include_directories(MonoScriptLibrary PRIVATE ${MONO_SCRIPT_LIBRARY_PATH}/mono/eglib)
# ----------------------------------------------------------------------------------------------------------------------
