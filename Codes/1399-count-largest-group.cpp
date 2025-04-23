/*
 * @Author: LetMeFly
 * @Date: 2025-04-23 13:17:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-23 13:19:12
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> bin;
        int maxTimes = 0;
        for (int i = 1; i <= n; i++) {
            int cnt = 0, temp = i;
            while (temp) {
                cnt += temp % 10;
                temp /= 10;
            }
            maxTimes = max(maxTimes, ++bin[cnt]);
        }
        int ans = 0;
        for (auto [a, b] : bin) {
            ans += b == maxTimes;
        }
        return ans;
    }
};