#include "UtilFile.h"

#ifdef _WIN32
# include <io.h>
# define F_OK 0
#else /* ifdef _WIN32 */
# include <unistd.h>
#endif /* ifdef _WIN32 */

namespace Util {

bool File::isFileExist(const char *path)
{
    return 0 == access(path, F_OK);
}

}
