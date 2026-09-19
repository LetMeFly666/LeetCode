/*
 * @Author: LetMeFly
 * @Date: 2026-09-19 10:04:00
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-19 10:06:38
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maximumLengthSubstring(string& s) {
        int ans = 0;
        int cnt[26] = {0};
        for (int l = 0, r = 0, n = s.size(), type_cnt = 0; r < n; r++) {
            int idx = s[r] - 'a';
            if (!cnt[idx]++) {
                type_cnt++;
            }
            while (type_cnt == 3) {
                if (!--cnt[s[l++] - 'a']) {
                    type_cnt--;
                }
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
