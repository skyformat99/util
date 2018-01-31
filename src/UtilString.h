#ifndef UTILSTRING_H
#define UTILSTRING_H

#include <iostream>
#include <vector>

namespace Util {

class String {
public:
    static bool compare(const std::string& str1, const std::string& str2,
                        bool ignoreCase = true);
    static std::string &toLowerCase(std::string& str);
    static std::string &toUpCase(std::string& str);
    static std::string& stripQuotes(std::string& str);
    static std::string& trim(std::string& str, std::string s = " \t");
    // 可以按多个字符来分割
    static std::vector<std::string> split(const std::string &s,
                                          const std::string &seperator);
};

} // namespace Util



#endif // UTILSTRING_H
