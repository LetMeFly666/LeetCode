/*
 * @Author: LetMeFly
 * @Date: 2025-06-10 23:07:14
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-10 23:14:08
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxDifference(string s) {
        int cnt[26] = {0};
        for (char c : s) {
            cnt[c - 'a']++;
        }
        int a1 = 0, a2 = 100;
        for (int c : cnt) {
            if (c % 2) {
                a1 = max(a1, c);
            } else if (c) {
                a2 = min(a2, c);
            }
        }
        return a1 - a2;
    }
};