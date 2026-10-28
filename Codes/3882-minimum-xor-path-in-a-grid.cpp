/*
 * @Author: LetMeFly
 * @Date: 2026-10-28 14:47:39
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-28 15:10:52
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

constexpr int SIZE = 1 << 10;
typedef bitset<SIZE> state;
class Solution {
private:
    void transfer(const state& a, state& b, int val) {
        for (int i = 0; i < SIZE; i++) {
            if (a[i]) {
                b.set(i ^ val);
            }
        }
    }

    int getFirst(state& a) {
        for (int i = 0; i < SIZE; i++) {
            if (a[i]) {
                return i;
            }
        }
        return -1;  // SHOULD NOT BE ACCESSED
    }
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<state>> res(n, vector<state>(m));
        res[0][0].set(grid[0][0]);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i) {
                    transfer(res[i - 1][j], res[i][j], grid[i][j]);
                }
                if (j) {
                    transfer(res[i][j - 1], res[i][j], grid[i][j]);
                }
            }
        }
        return getFirst(res[n - 1][m - 1]);
    }
};
