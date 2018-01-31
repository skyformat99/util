#include "UtilBase64.h"

#include "base64.h"

namespace Util {

struct base64_context Base64::m_base64;
bool Base64::m_isInit = false;

std::string Base64::encode(const char *data, size_t len)
{
    if (!m_isInit)
    {
        base64_init(&m_base64, 78);
        m_isInit = true;
    }

    int outLen = base64_get_encode_length(&m_base64, len);

    std::string str;
    str.reserve(outLen+1);

    base64_encode(&m_base64, data, len, (char*)str.c_str(), &outLen);

    return str;
}

size_t Base64::decode(const std::string &src, char **outBuf)
{
    if (!m_isInit)
    {
        base64_init(&m_base64, 78);
        m_isInit = true;
    }

    int outLen = (src.length()*3+3)/4 + 1;
    int realOutLen = 0;
    *outBuf = new char[outLen];
    base64_decode(&m_base64, src.c_str(), src.length(), *outBuf, &realOutLen);
    if (0 >= realOutLen)
    {
        realOutLen = 0;
        delete [] *outBuf;
        *outBuf = nullptr;
    }

    return realOutLen;
}

size_t Base64::decode(const char *data, size_t len, char **outBuf)
{
    if (!m_isInit)
    {
        base64_init(&m_base64, 78);
        m_isInit = true;
    }

    int outLen = (len*3+3)/4 + 1;
    int realOutLen = 0;
    *outBuf = new char[outLen];
    base64_decode(&m_base64, data, len, *outBuf, &realOutLen);
    if (0 >= realOutLen)
    {
        realOutLen = 0;
        delete [] *outBuf;
        *outBuf = nullptr;
    }

    return realOutLen;
}

} // namespace Util
