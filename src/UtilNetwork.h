#ifndef UTILNETWORK_H
#define UTILNETWORK_H

#include <iostream>

namespace Util {

class Network {
public:
    static std::string ipInt2String(uint32_t ip);
    static std::string ipFormat(const char *ip, bool isipv6 = true);
    static uint32_t ipString2Int(const std::string& ip);
};

} // namespace Util



#endif // UTILNETWORK_H
