# ----------------------------------------------------------------------------------------------------------------------
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/MonoScript/jitprofiling.h)
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/MonoScript/cpu-amd64.h)

FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/MonoScript/version.h
    "#ifndef MONO_SCRIPT_VERSION_H\n"
    "#define MONO_SCRIPT_VERSION_H\n\n"

    "#define FULL_VERSION \"Unknown(TODO)\"\n"

    "#endif // MONO_SCRIPT_VERSION_H\n"
)
# ----------------------------------------------------------------------------------------------------------------------
FILE(WRITE ${MONO_SCRIPT_CONFIG_PATH}/config.h
    "#ifndef MONO_SCRIPT_CONFIG_H\n"
    "#define MONO_SCRIPT_CONFIG_H\n\n"

    "#define ENABLE_EXPERIMENT_null\n\n"
    "#define USED_CROSS_COMPILER_OFFSETS 1\n\n"

    "#ifdef WIN32\n"
        "\t#define NVALGRIND\n"
        "\t#include \"${MONO_SCRIPT_LIBRARY_PATH}/winconfig.h\"\n\n"

        "#include \"${MONO_SCRIPT_LIBRARY_PATH}/msvc/msvc-disabled-warnings.h\"\n\n"

        "\t#define WIN32_LEAN_AND_MEAN\n"
        "\t#include <WinSock2.h>\n"
        "\t#include <WS2tcpip.h>\n"
        "\t#include <Windows.h>\n"
    "#endif\n\n"

    "#endif // MONO_SCRIPT_CONFIG_H\n"
)
# ----------------------------------------------------------------------------------------------------------------------