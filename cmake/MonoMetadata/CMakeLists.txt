cmake_minimum_required(VERSION 3.16)
project(MonoMetadata)

set(CMAKE_CXX_STANDARD 20)

if (WIN32 AND MONO_SCRIPT_CROSS)
    FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/MonoScript/Metadata/offsets.h
        "#if defined(DECL_ALIGN2) && !defined(DISABLE_JIT_OFFSETS)\n"
            "\tDECL_ALIGN2(gint8, 1)\n"
            "\tDECL_ALIGN2(gint16, 2)\n"
            "\tDECL_ALIGN2(gint32, 4)\n"
            "\tDECL_ALIGN2(gint64, 8)\n"
            "\tDECL_ALIGN2(float, 4)\n"
            "\tDECL_ALIGN2(double, 8)\n"
            "\tDECL_ALIGN2(gpointer, 8)\n"
        "#endif"
    )
endif()

FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/MonoScript/Metadata/config.h
    "#ifndef MONO_SCRIPT_CONFIG_H\n"
    "#define MONO_SCRIPT_CONFIG_H\n\n"

    "#define ENABLE_EXPERIMENT_null\n\n"
    "#define USED_CROSS_COMPILER_OFFSETS 1\n\n"

    "#ifdef _MSC_VER\n"
        "\t#pragma warning (disable: 4005)\n"
        "\t#pragma warning (disable: 4067)\n"
        "\t#pragma warning (disable: 4133)\n"
        "\t#pragma warning (disable: 4090)\n"
        "\t#pragma warning (disable: 4028)\n"
        "\t#pragma warning (disable: 4098)\n"
    "#endif\n\n"

    "#ifdef WIN32\n"
        "\t#define NVALGRIND\n"
        "\t#include \"${MONO_SCRIPT_LIBRARY_PATH}/winconfig.h\"\n"

        "\t#define WIN32_LEAN_AND_MEAN\n"
        "\t#include <WinSock2.h>\n"
        "\t#include <WS2tcpip.h>\n"
        "\t#include <Windows.h>\n"
    "#endif\n\n"

    "#endif // MONO_SCRIPT_CONFIG_H\n"
)

list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/marshal.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/class.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/class-accessors.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/class-init.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/class-setup-vtable.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/cominterop.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/exception.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/gc.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/image.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/environment.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/domain.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/appdomain.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/assembly.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/assembly-load-context.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/attach.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/boehm-gc.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/callspec.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/console-null.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/coree.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/custom-attrs.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/debug-helpers.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/debug-mono-ppdb.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/debug-mono-symfile.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/dynamic-image.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/dynamic-stream.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/filewatcher.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/gc-stats.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/handle.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/icall.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/icall-table.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/icall-eventpipe.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/jit-info.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/loaded-images.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/loaded-images-global.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/loader.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/lock-tracer.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/marshal-ilgen.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/metadata.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/mempool.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/memory-manager.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/metadata-cross-helpers.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/metadata-update.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/metadata-verify.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/method-builder.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/method-builder-ilgen.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/monitor.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/mono-basic-block.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/null-gc.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/null-gc-handles.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/mono-config.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/mono-config-dirs.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/mono-debug.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/mono-perfcounters.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/mono-endian.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/mono-hash.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/mono-mlist.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/mono-route.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/mono-security.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/native-library.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/native-library-qcall.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/opcodes.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/profiler.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/property-bag.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/rand.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/reflection.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/remoting.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/runtime.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/security-core-clr.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/security-manager.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/seq-points-data.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/sgen-bridge.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/sgen-mono.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/sgen-mono-ilgen.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/sgen-new-bridge.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/sgen-old-bridge.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/sgen-stw.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/sgen-tarjan-bridge.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/sgen-toggleref.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/sre.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/sre-encode.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/sre-save.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/string-icalls.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/support.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/sysmath.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/system_net_security_native_empty.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/threadpool.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/threadpool-io.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/threadpool-io-epoll.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/threadpool-worker-default.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/threads.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/verify.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/mono-conc-hash.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/object.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/threads.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/debug-mono-ppdb.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/abi.c)

#list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/threadpool-worker-wasm.c)
#list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/external-only.c)

if (WIN32)
    list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/w32socket.c)
    list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/w32process.c)
    list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/w32file.c)
    list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/w32handle.c)

    list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/w32semaphore-win32.c)
    list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/w32event-win32.c)
    list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/w32process-win32.c)
    list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/w32mutex-win32.c)
    list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/w32file-win32.c)
    list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/mono-security-windows.c)
    list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/marshal-windows.c)
    list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/icall-windows.c)
    list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/file-mmap-windows.c)
    list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/w32socket-win32.c)


    FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/MonoScript/Metadata/w32error-win32-fixed.c
        "#include \"${CMAKE_CURRENT_BINARY_DIR}/MonoScript/Metadata/config.h\"\n"
        "#include \"${MONO_SCRIPT_LIBRARY_PATH}/mono/metadata/w32error-win32.c\"\n"
    )

    list(APPEND MONO_SCRIPT_METADATA_SOURCES ${CMAKE_CURRENT_BINARY_DIR}/MonoScript/Metadata/w32error-win32-fixed.c)
endif()

# ----------------------------------------------------------------------------------------------------------------------
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/sgen/sgen-gc.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/sgen/sgen-hash-table.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/sgen/sgen-alloc.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/sgen/sgen-cardtable.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/sgen/sgen-debug.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/sgen/sgen-descriptor.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/sgen/sgen-gray.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/sgen/sgen-internal.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/sgen/sgen-fin-weak-hash.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/sgen/sgen-gchandles.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/sgen/sgen-layout-stats.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/sgen/sgen-los.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/sgen/sgen-marksweep.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/sgen/sgen-memory-governor.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/sgen/sgen-nursery-allocator.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/sgen/sgen-pinning.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/sgen/sgen-pinning-stats.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/sgen/sgen-pointer-queue.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/sgen/sgen-protocol.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/sgen/sgen-qsort.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/sgen/sgen-simple-nursery.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/sgen/sgen-split-nursery.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/sgen/sgen-thread-pool.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/sgen/sgen-workers.c)
list(APPEND MONO_SCRIPT_METADATA_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/sgen/sgen-array-list.c)
# ----------------------------------------------------------------------------------------------------------------------

add_library(MonoScriptMetadata STATIC ${MONO_SCRIPT_METADATA_SOURCES})

#if ((WIN32) AND (MONO_SCRIPT_CROSS))
    target_compile_definitions(MonoScriptMetadata PRIVATE USED_CROSS_COMPILER_OFFSETS=1)
    target_compile_definitions(MonoScriptMetadata PRIVATE MONO_CROSS_COMPILE=1)
    target_compile_definitions(MonoScriptMetadata PRIVATE MONO_OFFSETS_FILE=<${CMAKE_CURRENT_BINARY_DIR}/MonoScript/Metadata/offsets.h>)
#endif()

target_compile_definitions(MonoScriptMetadata PRIVATE HAVE_SGEN_GC)

target_include_directories(MonoScriptMetadata PRIVATE ${MONO_SCRIPT_LIBRARY_PATH}/mono)
target_include_directories(MonoScriptMetadata PRIVATE ${MONO_SCRIPT_LIBRARY_PATH})
target_include_directories(MonoScriptMetadata PRIVATE ${MONO_SCRIPT_LIBRARY_PATH}/mono/eglib)
target_include_directories(MonoScriptMetadata PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/MonoScript/Metadata)
