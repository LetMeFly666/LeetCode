/*
 * @Author: LetMeFly
 * @Date: 2023-09-26 08:39:51
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-09-26 08:46:11
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int passThePillow(int n, int time) {
        time %= (n - 1) * 2;
        return time <= n - 1 ? time + 1 : 2 * n - time - 1;
    }
};