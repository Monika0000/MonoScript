//
// Created by Monika on 04.12.2022.
//

#ifndef MONOSCRIPTTEST_FUNCTIONSHOLDER_H
#define MONOSCRIPTTEST_FUNCTIONSHOLDER_H

#include <MonoScript/stdInclude.h>

namespace MonoScript {
    namespace Utils {
        struct FunctionsHolder {
            std::function<void(const std::string &)> log;
            std::function<void(const std::string &)> error;
            std::function<void(const std::string &)> warn;
        };

        MST_EXTERN MST_EXPORT FunctionsHolder *GetFunctionsHolder();

        static void Log(const std::string &msg);
        static void Warn(const std::string &msg);
        static void Error(const std::string &msg);
    }
}

#define MST_LOG(msg) MonoScript::Utils::Log(msg)
#define MST_WARN(msg) MonoScript::Utils::Warn(msg)
#define MST_ERROR(msg) MonoScript::Utils::Error(msg)

#endif //MONOSCRIPTTEST_FUNCTIONSHOLDER_H
