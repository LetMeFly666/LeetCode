/*
 * @Author: LetMeFly
 * @Date: 2026-02-19 11:16:44
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-19 11:19:11
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0;
        for (int i = 1, n = s.size(), cnt = 1, lastCnt = 0; i <= n; i++) {
            if (i == n || s[i] != s[i - 1]) {
                ans += min(cnt, lastCnt);
                lastCnt = cnt;
                cnt = 1;
            }
        }
        return ans;
    }
};