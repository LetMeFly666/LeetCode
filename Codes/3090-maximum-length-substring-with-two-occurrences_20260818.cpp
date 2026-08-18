/*
 * @Author: LetMeFly
 * @Date: 2026-08-18 17:24:17
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-08-18 17:26:09
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maximumLengthSubstring(string& s) {
        int ans = 0;
        int cnt[26] = {0};
        for (int l = 0, r = 0, n = s.size(); r < n; r++) {
            int th = s[r] - 'a';
            cnt[th]++;
            while (cnt[th] > 2) {
                cnt[s[l++] - 'a']--;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
