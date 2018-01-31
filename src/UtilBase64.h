#ifndef UTILBASE64_H
#define UTILBASE64_H

#include <iostream>

struct base64_context;

namespace Util {

class Base64 {
public:
    static std::string encode(const char* data, size_t len);
    static size_t decode(const std::string& src, char** outBuf);
    static size_t decode(const char* data, size_t len, char** outBuf);
private:
    static struct base64_context m_base64;
    static bool m_isInit;
};

} // namespace Util


#endif // UTILBASE64_H
