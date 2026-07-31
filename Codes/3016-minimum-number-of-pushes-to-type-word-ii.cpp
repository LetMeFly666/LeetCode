/*
 * @Author: LetMeFly
 * @Date: 2026-07-31 08:21:21
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-31 08:24:25
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minimumPushes(string& word) {
        int cnt[26] = {0};
        for (char c : word) {
            cnt[c - 'a']++;
        }
        ranges::sort(cnt, greater<>());
        int ans = 0, round = 1, th = 0;
        for (int t : cnt) {
            th++;
            if (th == 9) {
                th = 1;
                round++;
            }
            ans += t * round;
        }
        return ans;
    }
};
