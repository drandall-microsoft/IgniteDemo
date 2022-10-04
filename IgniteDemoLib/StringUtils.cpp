#include "pch.h"
#include "StringUtils.h"

#include <cstring>

namespace StrUtil {
    void Concat(const char* lhs, const char* rhs, char** buffer) {
        *buffer = new char[strlen(lhs) + strlen(rhs)];
        char* buf = *buffer;

        int index = 0;
        for(int i = 0; i < strlen(lhs); ++index, ++i) {
            buf[index] = lhs[i];
        }
        buf[index++] = ' ';
        for(int i = 0; i < strlen(rhs); ++index, ++i) {
            buf[index] = rhs[i];
        }
    }
} // namespace StrUtil
