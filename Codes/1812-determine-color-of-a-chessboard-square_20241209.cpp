/*
 * @Author: LetMeFly
 * @Date: 2024-12-09 16:57:48
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-09 16:58:00
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool squareIsWhite(string coordinates) {
        return coordinates[0] % 2 != coordinates[1] % 2;
    }
};