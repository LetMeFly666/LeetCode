/*
 * @Author: LetMeFly
 * @Date: 2026-06-30 12:22:55
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-01 15:38:27
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        int cnt[3] = {0};
        for (int l = 0, r = 0, n = s.size(); r < n; r++) {
            cnt[s[r] - 'a']++;
            while (cnt[0] && cnt[1] && cnt[2]) {
                cnt[s[l++] - 'a']--;
            }
            ans += l;
        }
        return ans;
    }
};
