#include <MonoScript/Utils/FunctionsHolder.h>

#include <Windows.h>

static MonoString* Sample() {
    return mono_string_new(mono_domain_get(), "Hello!");
}

int main() {
    MonoAllocatorVTable mem_vtable = { MONO_ALLOCATOR_VTABLE_VERSION, malloc, NULL, NULL, NULL };
    mono_set_allocator_vtable (&mem_vtable);

    mono_config_parse (NULL);

    mono_assembly_setrootdir("../Resources");

    MonoDomain* domain = mono_jit_init_version ("unit-test-app", "v4.0.30319");

    //MonoAssembly *assembly = mono_domain_assembly_open (domain, "file.exe");
    //if (!assembly)
    //    error ();

    mono_jit_cleanup (domain);

    return 0;
}