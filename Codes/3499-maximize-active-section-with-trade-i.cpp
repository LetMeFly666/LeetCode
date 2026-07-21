/*
 * @Author: LetMeFly
 * @Date: 2026-07-21 09:30:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-21 09:48:29
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxActiveSectionsAfterTrade(string& s) {
        int cnt1 = 0, max0 = -1000000;
        for (int last_cnt0 = -1000000, now_cnt0 = 0, i = 0, n = s.size(); i <= n; i++) {
            if (i < n && s[i] == '0') {
                now_cnt0++;
            } else if (i && s[i - 1] == '0') {  // 0->1
                max0 = max(max0, last_cnt0 + now_cnt0);
                last_cnt0 = now_cnt0;
                now_cnt0 = 0;
            }
            cnt1 += i < n && s[i] == '1';
        }
        return cnt1 + max(max0, 0);
    }
};
