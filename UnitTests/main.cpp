#include <MonoScript/Utils/FunctionsHolder.h>
#include <MonoScript/Compiler/Compiler.h>

int main() {
    MonoScript::Utils::GetFunctionsHolder()->log = [](auto&& msg) {
        std::cout << "[LOG] " << msg << std::endl;
    };

    MonoScript::Utils::GetFunctionsHolder()->warn = [](auto&& msg) {
        std::cout << "[WARN] " << msg << std::endl;
    };

    MonoScript::Utils::GetFunctionsHolder()->error = [](auto&& msg) {
        std::cout << "[ERROR] " << msg << std::endl;
    };

    MonoScript::test();

    return 0;
}