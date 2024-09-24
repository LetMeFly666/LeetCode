/*
 * @Author: LetMeFly
 * @Date: 2024-09-24 18:46:23
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-09-24 18:49:24
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef long long ll;

class Solution {
public:
    ll maximumSubsequenceCount(string text, string pattern) {
        ll ans = 0;
        ll cnt0= 0, cnt1 = 0;
        for (char c : text) {
            if (c == pattern[1]) {
                cnt1++;
                ans += cnt0;
            }
            if (c == pattern[0]) {
                cnt0++;
            }
        }
        return ans + max(cnt0, cnt1);
    }
};