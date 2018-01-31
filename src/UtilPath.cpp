#include "UtilPath.h"

namespace Util {

std::string Path::join(const std::string &path1, const std::string &path2)
{
    std::string path = path1 + path2;
    return path;
}

}

