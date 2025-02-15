/*
 * @Author: LetMeFly  // 中间中断了
 * @Date: 2025-02-15 11:04:20
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-15 11:19:25
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    void drop(vector<vector<int>>& grid, vector<int>& ans, int j) {
        int x = 0, y = j;
        while (x < grid.size()) {
            int nextY = y + grid[x][y];
            if (nextY < 0 || nextY >= grid[0].size() || grid[x][y] != grid[x][nextY]) {
                return;
            }
            x++, y = nextY;
        }
        ans[j] = y;
    } 
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans(grid[0].size(), -1);
        for (int j = 0; j < grid[0].size(); j++) {
            drop(grid, ans, j);
        }
        return ans;
    }
};