cmake_minimum_required(VERSION 3.16)
project(zlib)

set(CMAKE_CXX_STANDARD 20)

add_library(zlib STATIC
    ${MONO_SCRIPT_LIBRARY_PATH}/mono/zlib/adler32.c
    ${MONO_SCRIPT_LIBRARY_PATH}/mono/zlib/compress.c
    ${MONO_SCRIPT_LIBRARY_PATH}/mono/zlib/crc32.c
    ${MONO_SCRIPT_LIBRARY_PATH}/mono/zlib/deflate.c
    ${MONO_SCRIPT_LIBRARY_PATH}/mono/zlib/infback.c
    ${MONO_SCRIPT_LIBRARY_PATH}/mono/zlib/inffast.c
    ${MONO_SCRIPT_LIBRARY_PATH}/mono/zlib/inflate.c
    ${MONO_SCRIPT_LIBRARY_PATH}/mono/zlib/inftrees.c
    ${MONO_SCRIPT_LIBRARY_PATH}/mono/zlib/trees.c
    ${MONO_SCRIPT_LIBRARY_PATH}/mono/zlib/uncompr.c
    ${MONO_SCRIPT_LIBRARY_PATH}/mono/zlib/zutil.c
)