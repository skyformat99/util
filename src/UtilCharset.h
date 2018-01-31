#ifndef UTILCHARSET_H
#define UTILCHARSET_H

#include <stdio.h>

namespace Util {

class Charset {
public:
    static size_t covert(const char *fromCharset, const char *toCharset,
                         char *inBuf, size_t inLen, char*outBuf, size_t outLen);
};

} // namespace Util

#endif // UTILCHARSET_H
