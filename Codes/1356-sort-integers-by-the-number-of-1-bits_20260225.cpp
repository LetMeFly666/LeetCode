/*
 * @Author: LetMeFly
 * @Date: 2026-02-25 21:36:09
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-26 22:05:15
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](const int& a, const int& b) {
            int ca = __builtin_popcount(a);
            int cb = __builtin_popcount(b);
            return ca != cb ? ca < cb : a < b;
        });
        return arr;
    }
};
