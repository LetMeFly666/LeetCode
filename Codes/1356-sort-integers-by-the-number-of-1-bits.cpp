/*
 * @Author: LetMeFly
 * @Date: 2022-04-22 08:47:36
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-22 08:51:23
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

inline bool cmp(const int& a, const int& b) {
    int diff = __builtin_popcount(a) - __builtin_popcount(b);
    if (diff)
        return diff < 0;
    return a < b;
}

class Solution {
public:
    vector<int>& sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};