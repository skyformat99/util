#include "UtilNetwork.h"
#include <string.h>

#ifdef _WIN32

# include <Windows.h>
# include <winsock.h>

#else /* ifdef _WIN32 */

# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>

#endif /* ifdef _WIN32 */

namespace Util {

std::string Network::ipInt2String(uint32_t ip)
{
    struct in_addr naddr;
    naddr.s_addr = ip;
    return inet_ntoa(naddr);
}

std::string Network::ipFormat(const char* ip, bool isipv6)
{
    if (isipv6)
    {
        char buf[40] = {0};
        sprintf(buf, "%0x%0x:%0x%0x:%0x%0x:%0x%0x:%0x%0x:%0x%0x:%0x%0x:%0x%0x",
                ip[0], ip[1], ip[2], ip[3], ip[4], ip[5], ip[6], ip[7],
                ip[8], ip[9], ip[10], ip[11], ip[12], ip[13], ip[14], ip[15]);
        return buf;
    }
    else
    {
        uint32_t ipInt;
        memcpy(&ipInt, ip, 4);
        struct in_addr naddr;
        naddr.s_addr = ipInt;
        return inet_ntoa(naddr);
    }
}

uint32_t Network::ipString2Int(const std::string &ip)
{
#ifdef _WIN32
    unsigned long ret;
#else
    in_addr_t ret;
#endif
    ret = inet_addr(ip.c_str());
    return ntohl(ret);
}

} // namespace Util
