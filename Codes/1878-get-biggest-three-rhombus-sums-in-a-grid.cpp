/*
 * @Author: LetMeFly
 * @Date: 2026-03-16 22:56:57
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-03-16 23:44:05
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

/*
(i, j) -> (x, y): diag[x+1][y+1] - diag[i][j]
(i, j) -> (x, y): anti[x+1][y] - anti[i][j+1]
*/
class Solution {
private:
    int x = 0, y = 0, z = 0;  // 三大
    vector<vector<int>> diag, anti;

    void update(int v) {
        if (v >= x) {
            z = y, y = x, x = v;
        } else if (v >= y) {
            z = y, y = v;
        } else if (v > z) {
            z = v;
        }
    }

    void calc(int i, int j, int k) {
        if (!k) {
            return update(diag[i + 1][j + 1] - diag[i][j]);
        }
        // 上：i - k, j
        // 下：i + k, j
        // 左：i, j - k
        // 右：i, j + k
        int val = 0
            + diag[i][j + k] - diag[i - k][j]                  // ↘ [上, 右)：(i-k, j)->(i, j+k) | (i-k,j)->(i-1, j+k-1)
            + diag[i + k + 1][j + 1] - diag[i + 1][j - k + 1]  // ↘ (左, 下]：(i,j-k)->(i+k,j) | (i+1,j-k+1)->(i+k,j)
            + anti[i - k + 2][j - 1] - anti[i][i - k + 1]      // ↗ [左, 上)：(i,j-k)->(i-k,j) | (i,j-k)->(i-k+1,j-1)
            + anti[i][j + k + 1] - anti[i + k][j + 1];         //  ↗ (下, 右]：(i+k,j)->(i,j+k) | (i+k-1,j+1)->(i,j+k)
        update(val);
    }
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        diag = vector<vector<int>>(n + 1, vector<int>(m + 1));  // ↘
        anti = vector<vector<int>>(n + 1, vector<int>(m + 1));  // ↖
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                diag[i + 1][j + 1] = diag[i][j] + grid[i][j];
                anti[i + 1][j] = anti[i][j + 1] + grid[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0, max_k = min(i, min(j, min(n - i - 1, m - j - 1))); k <= max_k; k++) {
                    calc(i, j, k);
                }
            }
        }

        vector<int> ans;
        if (x) {
            ans.push_back(x);
        }
        if (y) {
            ans.push_back(y);
        }
        if (z) {
            ans.push_back(z);
        }
        return ans;
    }
};