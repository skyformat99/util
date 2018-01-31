#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <string.h>
#include <vector>

#include "./UtilString.h"
#include "./UtilPath.h"
#include "./UtilFile.h"
#include "./UtilDir.h"
#include "./UtilCharset.h"
#include "./UtilSystem.h"
#include "./UtilBase64.h"
#include "./UtilQuotedPrintable.h"
#include "./UtilNetwork.h"

#ifndef MIN
# define MIN(a,b) ((a)<=(b)?(a):(b))
#endif
#ifndef MAX
# define MAX(a,b) ((a)>=(b)?(a):(b))
#endif

namespace Util {

/// common function
class CUtil {
public:

};

}



#endif // UTIL_H
