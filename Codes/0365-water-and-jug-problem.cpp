/*
 * @Author: LetMeFly
 * @Date: 2022-10-05 21:23:36
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-05 21:31:54
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

// 3, 5 -> 4:  3, 0 -> 0, 3 -> 3, 3 -> 1, 5 -> 1, 0 -> 0, 1 -> 3, 1 -> 0, 4

// Copy
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (x + y < z) {
            return false;
        }
        if (x == 0 || y == 0) {
            return z == 0 || x + y == z;
        }
        return z % gcd(x, y) == 0;
    }
};