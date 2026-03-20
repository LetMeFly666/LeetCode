#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n - k + 1, vector<int>(m - k + 1));
        for (int i = 0; i < n - k + 1; i++) {
            for (int j = 0; j < m - k + 1; j++) {
                int m = grid[i][j], M = m;
                for (int di = 0; di < k; di++) {
                    for (int dj = 0; dj < k; dj++) {
                        m = min(m, grid[i + di][j + dj]);
                        M = max(M, grid[i + di][j + dj]);
                    }
                }
                ans[i][j] = M - m;
            }
        }
        return ans;
    }
};