#ifndef UTILQUOTEDPRINTABLE_H
#define UTILQUOTEDPRINTABLE_H

#include <iostream>

namespace Util {

class QuotedPrintable {
public:
    static std::string encode(const char* data, size_t len, size_t maxLine = 76);
    static size_t decode(const char* data, size_t len, char** outBuf);
};

} // namespace Util

#endif // UTILQUOTEDPRINTABLE_H
