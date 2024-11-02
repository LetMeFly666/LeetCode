/*
 * @Author: LetMeFly
 * @Date: 2024-11-02 10:52:32
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-02 10:52:47
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minChanges(int n, int k) {
        return (n | k) == n ? __builtin_popcount(n ^ k) : -1;
    }
};