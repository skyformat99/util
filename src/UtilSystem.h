#ifndef UTILSYSTEM_H
#define UTILSYSTEM_H

#include <string.h>
#include <iostream>

namespace Util {

class System {
public:
    static bool isBigEnding();
    static std::string getSystemCharset();

    /// 模板函数
    template<typename _T>
    static _T switchEnding(_T n) {
        int len = sizeof(n);
        _T ret;
        for (int i=0; i<len; i++){
            memcpy((char*)&ret+i, (char*)&n+len-i-1, 1);
        }
        return ret;
    }
};

}



#endif // UTILSYSTEM_H
