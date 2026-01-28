/*
 * @Author: LetMeFly
 * @Date: 2026-01-28 23:02:19
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-28 23:23:30
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    void normalRightDownDP(vector<vector<int>>& grid, vector<vector<int>>& dp) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (i > 0) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + grid[i][j]);
                }
                if (j > 0) {
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + grid[i][j]);
                }
            }
        }
    }
public:
    int minCost(vector<vector<int>>& grid, int k) {
        unordered_map<int, vector<pair<int, int>>> graph;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                graph[grid[i][j]].push_back({i, j});
            }
        }
        vector<int> heights;
        heights.reserve(graph.size());
        for (auto [height, _] : graph) {
            heights.push_back(height);
        }
        sort(heights.begin(), heights.end(), greater<int>());

        vector<vector<vector<int>>> dp(k + 1, vector<vector<int>>(grid.size(), vector<int>(grid[0].size(), 10000000)));
        dp[0][0][0] = 0;
        normalRightDownDP(grid, dp[0]);

        for (int times = 1; times <= k; times++) {
            int miniFrom = 10000000;
            for (int height : heights) {
                for (auto [x, y] : graph[height]) {
                    miniFrom = min(miniFrom, dp[times - 1][x][y]);
                }
                for (auto [x, y] : graph[height]) {
                    dp[times][x][y] = miniFrom;
                }
            }
            normalRightDownDP(grid, dp[times]);
        }
        return dp[k][grid.size() - 1][grid[0].size() - 1];
    }
};