/*
 * @Author: LetMeFly
 * @Date: 2026-02-23 11:30:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-23 11:37:10
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> ma;
        for (int i = 0, to = s.size() - k + 1; i < to; i++) {
            ma.insert(s.substr(i, k));
        }
        return ma.size() == (1 << k);
    }
};