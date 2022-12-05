//
// Created by Monika on 05.12.2022.
//

#include <MonoScript/Compiler/Compiler.h>

#include <mono/metadata/handle-decl.h>

#include <mono/mini/jit.h>

#include <mono/metadata/mono-config.h>
#include <mono/metadata/assembly.h>
#include <mono/metadata/debug-helpers.h>
#include <mono/metadata/assembly-internals.h>
#include <mono/metadata/callspec.h>
#include <mono/metadata/object.h>
#include <mono/utils/mono-counters.h>
#include <mono/mini/mini.h>
#include <mono/mini/mini-runtime.h>

/*
typedef struct {
    MonoObject *volatile *__raw;
} MonoObjectHandle1, MonoObjectHandleOut1, MonoObjectHandleInOut1;


typedef struct CompileAllThreadArgs {
    MonoAssembly *ass;
    int verbose;
    guint32 opts;
    guint32 recompilation_times;
} CompileAllThreadArgs;

static bool CompileAllMethodsThreadMainInner(CompileAllThreadArgs* args) {
    MonoAssembly *ass = args->ass;
    int verbose = args->verbose;
    MonoImage *image = mono_assembly_get_image_internal(ass);
    MonoMethod *method;
    MonoCompile *cfg;
    int count = 0, fail_count = 0;

    for (int i = 0; i < mono_image_get_table_rows(image, MONO_TABLE_METHOD); ++i) {
        ERROR_DECL (error);
        guint32 token = MONO_TOKEN_METHOD_DEF | (i + 1);
        MonoMethodSignature *sig;

        if (mono_metadata_has_generic_params(image, token))
            continue;

        method = mono_get_method_checked(image, token, NULL, NULL, error);
        if (!method) {
            mono_error_cleanup(error);//FIXME don't swallow the error
            continue;
        }

        if ((method->iflags & METHOD_IMPL_ATTRIBUTE_INTERNAL_CALL) ||
            (method->flags & METHOD_ATTRIBUTE_PINVOKE_IMPL) ||
            (method->iflags & METHOD_IMPL_ATTRIBUTE_RUNTIME) ||
            (method->flags & METHOD_ATTRIBUTE_ABSTRACT)
                ) {
            continue;
        }

        if (mono_class_is_gtd(method->klass)) {
            continue;
        }

        sig = mono_method_signature_internal(method);
        if (!sig) {
            char *desc = mono_method_full_name(method, TRUE);
            g_print("Could not retrieve method signature for %s\n", desc);
            g_free(desc);
            fail_count++;
            continue;
        }

        if (sig->has_type_parameters)
            continue;

        count++;
        if (verbose) {
            char *desc = mono_method_full_name(method, TRUE);
            g_print("Compiling %d %s\n", count, desc);
            g_free(desc);
        }
        if (mono_use_interpreter) {
            mini_get_interp_callbacks ()->create_method_pointer(method, TRUE, error);
            // FIXME There are a few failures due to DllNotFoundException related to System.Native
            if (verbose && !is_ok (error))
                g_print("Compilation of %s failed\n", mono_method_full_name(method, TRUE));
        } else {
            cfg = mini_method_compile(method, mono_get_optimizations_for_method(method, args->opts),
                                      mono_get_root_domain(), (JitFlags) JIT_FLAG_DISCARD_RESULTS, 0, -1);
            if (cfg->exception_type != MONO_EXCEPTION_NONE) {
                const char *msg = cfg->exception_message;
                if (cfg->exception_type == MONO_EXCEPTION_MONO_ERROR)
                    msg = mono_error_get_message(cfg->error);
                g_print("Compilation of %s failed with exception '%s':\n", mono_method_full_name(cfg->method, TRUE),
                        msg);
                fail_count++;
            }
            mono_destroy_compile(cfg);
        }
    }

    return fail_count == 0;
}

static void CompileAllMethodsThreadMain (gpointer void_args) {
    auto &&args = (CompileAllThreadArgs *) void_args;
    for (guint32 i = 0; i < args->recompilation_times; ++i) {
        CompileAllMethodsThreadMainInner(args);
    }
}

static void CompileAllMethods(MonoAssembly *ass, int verbose, guint32 opts, guint32 recompilation_times) {
    ERROR_DECL (error);
    CompileAllThreadArgs args;

    args.ass = ass;
    args.verbose = verbose;
    args.opts = opts;
    args.recompilation_times = recompilation_times;

    ///
    ///  Need to create a mono thread since compilation might trigger
    ///  running of managed code.
    ///
    mono_thread_create_checked (mono_domain_get (), (gpointer)CompileAllMethodsThreadMain, &args, error);
    mono_error_assert_ok(error);

    mono_thread_manage_internal();
}
*/
MonoAssembly* LoadAssembly(const char* filename, int verbose, int optimization, int recompilation_times) {
    MonoImageOpenStatus open_status;
    MonoAssemblyOpenRequest open_req;

    mono_assembly_request_prepare_open (&open_req, MONO_ASMCTX_DEFAULT, mono_domain_default_alc(mono_get_root_domain()));

    if (MonoAssembly* assembly = mono_assembly_request_open(filename, &open_req, &open_status)) {
        mono_callspec_set_assembly(assembly);
        //CompileAllMethods(assembly, verbose, optimization, recompilation_times);
        return assembly;
    }

    return nullptr;
}

void MonoScript::test() {
    const char* filename = "Z:/Repositories/MonoScript/UnitTests/Resources/script.cs";
    const int optimization = mono_parse_default_optimizations(nullptr);

    auto&& assembly = LoadAssembly(filename, 0, optimization, 1);

    MonoAllocatorVTable mem_vtable = { MONO_ALLOCATOR_VTABLE_VERSION, malloc, NULL, NULL, NULL };
    mono_set_allocator_vtable (&mem_vtable);

    mono_counters_init();
    mono_config_parse (NULL);

    mono_assembly_setrootdir("../Resources");

    MonoDomain* domain = mono_jit_init_version ("unit-test-app", "v4.0.30319");

    //MonoAssembly *assembly = mono_domain_assembly_open (domain, "file.exe");
    //if (!assembly)
    //    error ();

    mono_jit_cleanup (domain);
}