/*
 * @Author: LetMeFly
 * @Date: 2026-01-18 20:47:19
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-18 23:16:07
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

// THIS CANNOT BE ACCEPTED
class Solution {
private:
    vector<vector<int>> rowSum, colSum;

    bool ok(vector<vector<int>>& grid, int x, int y, int l) {
        int cnt = 0, cntRev = 0;
        for (int i = 0; i < l; i++) {
            cnt += grid[x + i][y + i];
            cntRev += grid[x + l - i - 1][y + l - i - 1];
        }
        if (cnt != cntRev) {
            return false;
        }
        for (int i = 0; i < l; i++) {
            if (rowSum[x + i][y + l] - rowSum[x + i][y] != cnt) {
                return false;
            }
            if (colSum[x + l][y + i] - colSum[x][y + i] != cnt) {
                return false;
            }
        }
        return true;
    }
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        rowSum.resize(n, vector<int>(m + 1));
        colSum.resize(n + 1, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                rowSum[i][j + 1] = rowSum[i][j] + grid[i][j];
                colSum[i + 1][j] = colSum[i][j] + grid[i][j];
            }
        }

        for (int k = n; k > 1; k--) {
            for (int i = 0; i + k <= n; i++) {
                for (int j = 0; j + k <= m; j++) {
                    if (ok(grid, i, j, k)) {
                        return k;
                    }
                }
            }
        }
        return 1;
    }
};