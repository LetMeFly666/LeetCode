/*
 * @Author: LetMeFly
 * @Date: 2026-03-01 19:50:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-03-01 19:51:09
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minPartitions(string n) {
        char M = '0';
        for (char c : n) {
            M = max(M, c);
        }
        return M - '0';
    }
};