/*
 * @Author: LetMeFly
 * @Date: 2025-03-19 23:29:19
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-19 23:30:32
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

/*
左指针向右：
diff = (b - a) * dis - a
     = b * dis - a * (dis + 1)
*/