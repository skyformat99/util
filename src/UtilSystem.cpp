#include "UtilSystem.h"

namespace Util {


bool System::isBigEnding()
{
    uint16_t x = 0x00ff;
    char c = *((char*)&x);
    return ('\0' == c);
}

std::string System::getSystemCharset()
{
#ifdef _WIN32
    return "GBK";
#else // _WIN32
    char* encoding = nullptr;
    std::string sysEncoding = "UTF8"; // DEFAULT
    encoding = secure_getenv("LANG");
    if (nullptr != encoding)
    {
        sysEncoding = std::string(encoding);
        size_t index = sysEncoding.find('.');
        if (std::string::npos != index)
        {
            sysEncoding = std::string(sysEncoding.c_str()+index+1);
        }
    }
    return sysEncoding;
#endif // _WIN32
}

} // namespace Util
