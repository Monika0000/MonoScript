//
// Created by Monika on 04.12.2022.
//

#include <MonoScript/Utils/FunctionsHolder.h>

namespace MonoScript {
    namespace Utils {
        FunctionsHolder *GetFunctionsHolder() {
            static FunctionsHolder *pHolder = nullptr;
            if (!pHolder) {
                pHolder = new FunctionsHolder();
            }

            return pHolder;
        }

        void Log(const std::string &msg) {
            auto &&holder = GetFunctionsHolder();
            if (holder && holder->log) {
                holder->log(msg);
            }
        }

        void Warn(const std::string &msg) {
            auto &&holder = GetFunctionsHolder();
            if (holder && holder->warn) {
                holder->warn(msg);
            }
        }

        void Error(const std::string &msg) {
            auto &&holder = GetFunctionsHolder();
            if (holder && holder->error) {
                holder->error(msg);
            }
        }
    }
}