/*
 * @Author: LetMeFly
 * @Date: 2026-03-26 21:49:18
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-03-26 22:02:29
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
private:
    inline ll getSum(vector<vector<int>>& grid) {
        ll ans = 0;
        for (vector<int>& row : grid) {
            for (int& t : row) {
                ans += t;
            }
        }
        return ans;
    }

    void rotate(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> after(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                after[j][n - i - 1] = grid[i][j];
            }
        }
        grid.swap(after);
    }

    bool ok(vector<vector<int>>& grid, ll half) {
        unordered_set<int> visited;
        ll now = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int& t : grid[i]) {
                visited.insert(t);
                now += t;
            }
            if (now == half || i && visited.count(now - half)) {
                return true;
            }
        }
        return false;
    }
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        ll sum = getSum(grid);
        if (sum % 2) {
            return false;
        }
        sum /= 2;

        for (int i = 0; i < 4; i++) {
            if (ok(grid, sum)) {
                return true;
            }
            if (i < 3) {
                rotate(grid);
            }
        }
        return false;
    }
};
