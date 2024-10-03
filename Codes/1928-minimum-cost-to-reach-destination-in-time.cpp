/*
 * @Author: LetMeFly
 * @Date: 2024-10-03 12:42:02
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-03 12:51:57
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        // vector<vector<pair<int, int>>> graph(passingFees.size());
        // for (vector<int>& edge : edges) {
        //     graph[edge[0]].push_back({edge[1], edge[2]});
        //     graph[edge[1]].push_back({edge[0], edge[2]});
        // }
        vector<vector<int>> dp(maxTime + 1, vector<int>(passingFees.size(), 10000000));
        dp[0][0] = passingFees[0];
        for (int t = 1; t <= maxTime; t++) {
            for (vector<int>& edge : edges) {
                int i = edge[0], j = edge[1], thisTime = edge[2];
                if (thisTime <= t) {
                    dp[t][j] = min(dp[t][j], dp[t - thisTime][i] + passingFees[j]);
                    dp[t][i] = min(dp[t][i], dp[t - thisTime][j] + passingFees[i]);
                }
            }
        }
        int ans = 10000000;
        for (int t = 0; t <= maxTime; t++) {
            ans = min(ans, dp[t].back());
        }
        return ans == 10000000 ? -1 : ans;
    }
};