/*
 * @Author: LetMeFly
 * @Date: 2024-10-13 23:45:54
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-13 23:47:56
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int twoEggDrop(int n) {
        vector<int> dp(n + 1, 100000);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] = min(dp[i], max(j, dp[i - j] + 1));
            }
        }
        return dp.back();
    }
};