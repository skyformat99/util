#ifndef UTILPATH_H
#define UTILPATH_H

#include <iostream>

namespace Util {

class Path {
public:
    static std::string join(const std::string& path1, const std::string& path2);
};

}

#endif // UTILPATH_H
