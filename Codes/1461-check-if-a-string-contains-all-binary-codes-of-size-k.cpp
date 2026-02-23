/*
 * @Author: LetMeFly
 * @Date: 2026-02-23 11:30:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-23 11:37:00
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif
// THIS CANNOT BE ACCEPTED
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> ma;
        for (int i = 0, n = s.size(); i < n; i++) {
            for (int l = 1; l <= k && i + l <= n; l++) {
                ma.insert(s.substr(i, l));
            }
        }
        return ma.size() == (1 << k);
    }
};