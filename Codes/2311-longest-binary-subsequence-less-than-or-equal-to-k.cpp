/*
 * @Author: LetMeFly
 * @Date: 2025-06-26 22:16:30
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-26 22:43:01
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int ans = 0, val = 0, k_length = 32 - __builtin_clz(k), n = s.size();  // k=0时k_length=0计算错误也不受影响
        for (int i = 0; i < n; i++) {
            if (s[n - i - 1] == '0') {
                ans++;
                continue;
            }
            if (i < k_length && val + (1 << i) <= k) {
                val += 1 << i;
                ans++;
            }
        }
        return ans;
    }
};