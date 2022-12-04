target_include_directories(MonoScript PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/libs/mono)

set(MONO_SCRIPT_LIBRARY_PATH ${CMAKE_CURRENT_SOURCE_DIR}/libs/mono)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/cmake/zlib)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/cmake/MonoMetadata)

# ----------------------------------------------------------------------------------------------------------------------
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/MonoScript/jitprofiling.h)
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/MonoScript/cpu-amd64.h)

FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/MonoScript/version.h
    "#ifndef MONO_SCRIPT_VERSION_H\n"
    "#define MONO_SCRIPT_VERSION_H\n\n"

    "#define FULL_VERSION \"Unknown(TODO)\"\n"

    "#endif // MONO_SCRIPT_VERSION_H\n"
)

FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/MonoScript/msvc/msvc-disabled-warnings.h
    "#ifdef _MSC_VER\n"
        "\t#pragma warning (disable: 4005)\n"
        "\t#pragma warning (disable: 4067)\n"
        "\t#pragma warning (disable: 4133)\n"
        "\t#pragma warning (disable: 4090)\n"
        "\t#pragma warning (disable: 4098)\n"
    "#endif\n\n"
)

FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/MonoScript/Mini/config.h
    "#ifndef MONO_SCRIPT_CONFIG_H\n"
    "#define MONO_SCRIPT_CONFIG_H\n\n"

    "#define ENABLE_EXPERIMENT_null\n\n"
    "#define USED_CROSS_COMPILER_OFFSETS 1\n\n"

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

list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/mini.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/aot-runtime.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/abcremoval.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/alias-analysis.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/driver.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/mini-runtime.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/mini-exceptions.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/calls.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/llvmonly-runtime.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/jit-icalls.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/cfold.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/cfgdump.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/debugger-agent.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/debug-mini.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/debugger-engine.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/seq-points.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/mini-native-types.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/mini-generic-sharing.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/mini-trampolines.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/mini-codegen.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/method-to-ir.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/decompose.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/unwind.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/dominators.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/liveness.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/graph.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/trace.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/dwarfwriter.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/debugger-state-machine.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/genmdesc.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/helpers.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/image-writer.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/interp-stubs.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/intrinsics.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/linear-scan.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/lldb.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/local-propagation.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/memory-access.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/monovm.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/mini-gc.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/simd-intrinsics.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/ssa.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/tasklets.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/tiered.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/type-checking.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/xdebug.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/mini-profiler.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/branch-opts.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/aot-compiler.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/mini-cross-helpers.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/aot-runtime.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/debugger-agent-stubs.c)

#list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/mini-mips.c)
#list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/llvm-jit.cpp)
#list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/llvm-runtime.cpp)

if (WIN32)
    list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/arch-stubs.c)
    list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/mini-amd64.c)
    list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/exceptions-amd64.c)
    list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/mini-amd64-gsharedvt.c)
    list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/tramp-amd64-gsharedvt.c)
    list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/tramp-amd64.c)
    list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/mini-windows.c)
    list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/mini-windows-tls-callback.c)
endif()

# ----------------------------------------------------------------------------------------------------------------------
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/interp/interp.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/interp/interp-intrins.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/interp/transform.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/interp/mintops.c)
#list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/mini/interp/whitebox.c)

# ----------------------------------------------------------------------------------------------------------------------
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/culture/locales.c)

# ----------------------------------------------------------------------------------------------------------------------
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/native/mono-native-platform.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/native/pal-icalls.c)

# ----------------------------------------------------------------------------------------------------------------------
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/profiler/helper.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/profiler/aot.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/profiler/log.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/profiler/log-args.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/profiler/proftest-pinvokes.c)

#list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/profiler/vtune.c)
#list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/profiler/mprof-report.c)

# ----------------------------------------------------------------------------------------------------------------------
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-threads.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-threads-coop.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-error.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/atomic.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/bsearch.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/checked-build.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/dlmalloc.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/hazard-pointer.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/json.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/lifo-semaphore.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/lock-free-alloc.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/lock-free-array-queue.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/memfuncs.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-context.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-cgroup.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-codeman.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-conc-hashtable.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-counters.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-dl.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-embed.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-experiments.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-filemap.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-linked-list-set.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-flight-recorder.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-hwcap.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-io-portability.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-internal-hash.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-jemalloc.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-logger.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-log-common.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-math-c.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-md5.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-merp.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-mmap.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-os-mutex.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-networkinterfaces.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-path.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/monobitset.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/parse.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/strenc.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/options.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/networking.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/networking-posix.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/networking-fallback.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/networking-missing.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-utils-debug.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-time.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-uri.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-utility-thread.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-value-hash.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-threads-state-machine.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-threads-mach-helper.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-threads.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-state.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-sha1.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-poll.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-log-flight-recorder.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-proclib.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-property-hash.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-publib.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-signal-handler.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-stdlib.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-tls.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/lock-free-queue.c)

list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mach-support-unknown.c)
list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-hwcap-cross.c)

if (WIN32)
    list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-proclib-windows.c)
    list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/networking-windows.c)
    list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-rand-windows.c)
    list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-windows-thread-name.c)
    list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-threads-windows.c)
    list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/os-event-win32.c)
    list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-mmap-windows.c)
    list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-os-wait-win32.c)
    list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-os-semaphore-win32.c)
    list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-log-windows.c)
    list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-threads-coop.c)
    list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/mono-dl-windows.c)

    #list(APPEND MONO_SCRIPT_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/utils/win64.asm)

    list(APPEND MONO_SCRIPT_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/inc/MonoScript/CPU/cpu-amd64.c)
endif()
# ----------------------------------------------------------------------------------------------------------------------
add_library(MonoScriptLibrary STATIC ${MONO_SCRIPT_SOURCES})

if (WIN32)
    target_compile_definitions(MonoScriptLibrary PRIVATE HAVE_API_SUPPORT_WIN32_LOAD_LIBRARY)
    target_compile_definitions(MonoScriptLibrary PRIVATE HAVE_API_SUPPORT_WIN32_CONSOLE=1)
    target_compile_definitions(MonoScriptLibrary PRIVATE HAVE_API_SUPPORT_WIN32_GET_MODULE_HANDLE)

    if (MONO_SCRIPT_CROSS)
        target_compile_definitions(MonoScriptLibrary PRIVATE USED_CROSS_COMPILER_OFFSETS=1)
        target_compile_definitions(MonoScriptLibrary PRIVATE MONO_CROSS_COMPILE=1)
    endif()
endif()

target_include_directories(MonoScriptLibrary PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/MonoScript/Mini)
target_include_directories(MonoScriptLibrary PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/MonoScript)
target_include_directories(MonoScriptLibrary PRIVATE ${MONO_SCRIPT_LIBRARY_PATH})

# ----------------------------------------------------------------------------------------------------------------------
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/MonoScript/eglib/config.h
    "#ifdef WIN32\n"
        "\t#define WIN32_LEAN_AND_MEAN\n"
        "\t#include <WinSock2.h>\n"
        "\t#include <WS2tcpip.h>\n"
        "\t#include <Windows.h>\n"
    "#endif\n\n"
)

list(APPEND MONO_SCRIPT_GLIB_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/eglib/garray.c)
list(APPEND MONO_SCRIPT_GLIB_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/eglib/glist.c)
list(APPEND MONO_SCRIPT_GLIB_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/eglib/gpath.c)
list(APPEND MONO_SCRIPT_GLIB_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/eglib/gstring.c)
list(APPEND MONO_SCRIPT_GLIB_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/eglib/gstr.c)
list(APPEND MONO_SCRIPT_GLIB_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/eglib/gbytearray.c)
list(APPEND MONO_SCRIPT_GLIB_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/eglib/gerror.c)
list(APPEND MONO_SCRIPT_GLIB_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/eglib/gmem.c)
list(APPEND MONO_SCRIPT_GLIB_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/eglib/gslist.c)
list(APPEND MONO_SCRIPT_GLIB_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/eglib/gfile.c)
list(APPEND MONO_SCRIPT_GLIB_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/eglib/ghashtable.c)
list(APPEND MONO_SCRIPT_GLIB_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/eglib/gmarkup.c)
list(APPEND MONO_SCRIPT_GLIB_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/eglib/giconv.c)
list(APPEND MONO_SCRIPT_GLIB_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/eglib/goutput.c)
list(APPEND MONO_SCRIPT_GLIB_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/eglib/gpattern.c)
list(APPEND MONO_SCRIPT_GLIB_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/eglib/gptrarray.c)
list(APPEND MONO_SCRIPT_GLIB_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/eglib/gqueue.c)
list(APPEND MONO_SCRIPT_GLIB_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/eglib/gshell.c)
list(APPEND MONO_SCRIPT_GLIB_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/eglib/gspawn.c)
list(APPEND MONO_SCRIPT_GLIB_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/eglib/gqsort.c)
list(APPEND MONO_SCRIPT_GLIB_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/eglib/gunicode.c)
list(APPEND MONO_SCRIPT_GLIB_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/eglib/gutf8.c)

if (WIN32)
    list(APPEND MONO_SCRIPT_GLIB_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/eglib/gmisc-win32.c)
    list(APPEND MONO_SCRIPT_GLIB_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/eglib/gfile-win32.c)
    list(APPEND MONO_SCRIPT_GLIB_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/eglib/gmodule-win32.c)
    list(APPEND MONO_SCRIPT_GLIB_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/eglib/gtimer-win32.c)
    list(APPEND MONO_SCRIPT_GLIB_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/eglib/gdir-win32.c)
    list(APPEND MONO_SCRIPT_GLIB_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/eglib/gdate-win32.c)
    list(APPEND MONO_SCRIPT_GLIB_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/eglib/gunicode-win32.c)

    list(APPEND MONO_SCRIPT_GLIB_SOURCES ${MONO_SCRIPT_LIBRARY_PATH}/mono/eglib/gfile-posix.c)
endif()

add_library(eglib STATIC ${MONO_SCRIPT_GLIB_SOURCES})

list(APPEND MONO_SCRIPT_LIBRARY_LINK version)
list(APPEND MONO_SCRIPT_LIBRARY_LINK Ws2_32)
list(APPEND MONO_SCRIPT_LIBRARY_LINK zlib)
list(APPEND MONO_SCRIPT_LIBRARY_LINK eglib)
list(APPEND MONO_SCRIPT_LIBRARY_LINK Winmm)
list(APPEND MONO_SCRIPT_LIBRARY_LINK Bcrypt)
list(APPEND MONO_SCRIPT_LIBRARY_LINK MonoScriptMetadata)

target_include_directories(eglib PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/MonoScript/eglib)
target_include_directories(eglib PRIVATE ${MONO_SCRIPT_LIBRARY_PATH}/mono/eglib)
# ----------------------------------------------------------------------------------------------------------------------
target_link_libraries(MonoScriptLibrary ${MONO_SCRIPT_LIBRARY_LINK})
target_include_directories(MonoScriptLibrary PRIVATE ${MONO_SCRIPT_LIBRARY_PATH}/mono)
target_include_directories(MonoScriptLibrary PRIVATE ${MONO_SCRIPT_LIBRARY_PATH})
target_include_directories(MonoScriptLibrary PRIVATE ${MONO_SCRIPT_LIBRARY_PATH}/mono/eglib)
# ----------------------------------------------------------------------------------------------------------------------
