/*
 * @Author: LetMeFly
 * @Date: 2024-11-05 09:51:00
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-05 09:52:13
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string losingPlayer(int x, int y) {
        return min(x, y / 4) % 2 ? "Alice" : "Bob";
    }
};