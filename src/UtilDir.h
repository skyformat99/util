#ifndef UTILDIR_H
#define UTILDIR_H

#include <iostream>
#include <vector>

namespace Util {

class Dir {
public:
    static std::string getAppDir();
    static bool isDirExist(const std::string &dir);
    static std::string getParentDir(const std::string& path);
    static bool mkDir(const std::string& dir);
    static bool fileList(std::vector<std::string>& files, const std::string &path,
                         bool recursive = false);
};

}


#endif // UTILDIR_H
