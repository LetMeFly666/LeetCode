/*
 * @Author: LetMeFly
 * @Date: 2026-09-19 10:04:00
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-19 10:10:52
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
            int idx = s[r] - 'a';
            cnt[idx]++;
            while (cnt[idx] == 3) {
                cnt[s[l] - 'a']--;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
