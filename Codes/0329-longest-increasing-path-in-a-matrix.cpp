/*
 * @Author: LetMeFly
 * @Date: 2022-09-25 20:42:39
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-09-25 20:48:20
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

struct MyNode {
    int x, y;
    int val;
};

bool cmp(const MyNode& a, const MyNode& b) {
    return a.val > b.val;
}

const int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<MyNode> nodes;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                nodes.push_back({i, j, matrix[i][j]});
            }
        }
        sort(nodes.begin(), nodes.end(), cmp);
        vector<vector<int>> dp(n, vector<int>(m, 1));
        int ans = 1;
        for (MyNode thisNode : nodes) {
            int x = thisNode.x, y = thisNode.y;
            int val = thisNode.val;
            for (int d = 0; d < 4; d++) {
                int tx = x + directions[d][0];
                int ty = y + directions[d][1];
                if (tx >= 0 && tx < n && ty >= 0 && ty < m) {
                    if (matrix[tx][ty] > val) {
                        dp[x][y] = max(dp[x][y], dp[tx][ty] + 1);
                    }
                }
            }
            ans = max(ans, dp[x][y]);
        }
        return ans;
    }
};