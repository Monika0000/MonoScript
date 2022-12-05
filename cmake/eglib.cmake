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

target_include_directories(eglib PRIVATE ${MONO_SCRIPT_CONFIG_PATH})
target_include_directories(eglib PRIVATE ${MONO_SCRIPT_LIBRARY_PATH})
target_include_directories(eglib PRIVATE ${MONO_SCRIPT_LIBRARY_PATH}/mono/eglib)