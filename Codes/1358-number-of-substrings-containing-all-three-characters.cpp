/*
 * @Author: LetMeFly
 * @Date: 2026-06-30 12:22:55
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-01 15:25:23
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        int cnt[3] = {0};
        cnt[s[0] - 'a']++;
        for (int l = 1, r = 0, n = s.size(); r < n; l++) {
            cnt[s[l - 1] - 'a']--;
            while (r < n && !(cnt[0] && cnt[1] && cnt[2])) {
                cnt[s[r++] - 'a']++;
            }
            ans += n - r;
        }
        return ans;
    }
};
