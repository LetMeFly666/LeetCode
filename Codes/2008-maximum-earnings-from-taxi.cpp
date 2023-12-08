/*
 * @Author: LetMeFly
 * @Date: 2023-12-08 22:50:56
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-12-08 23:10:54
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        unordered_map<int, vector<vector<int>>> ma;
        for (vector<int>& ride : rides) {
            ma[ride[1]].push_back(ride);
        }
        vector<long long> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];
            for (vector<int>& ride : ma[i]) {
                int start = ride[0], end = ride[1], tip = ride[2];
                dp[i] = max(dp[i], dp[start] + end - start + tip);
            }
        }
        return dp.back();
    }
};