/*
 * @Author: LetMeFly
 * @Date: 2026-10-11 09:50:25
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-11 09:52:07
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maximumLengthSubstring(const string& s) {
        int ans = 0;
        int cnt[26] = {0};
        for (int l = 0, r = 0, n = s.size(); r < n; r++) {
            cnt[s[r] - 'a']++;
            while (cnt[s[r] - 'a'] > 1) {
                cnt[s[l++] - 'a']--;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
