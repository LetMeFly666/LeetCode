/*
 * @Author: LetMeFly
 * @Date: 2026-05-09 21:35:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-05-09 22:09:11
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int n, m, k;
    vector<vector<int>> grid, ans;

    void init(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        this->grid = move(grid);
        this->k = k;
        ans.resize(n);
        for (int i = 0; i < n; i++) {
            ans[i].resize(m);
        }
    }

    void rotate(int th) {
        int m = this->m - 2 * th;
        int n = this->n - 2 * th;
        int all = (m + n) * 2 - 4;
        k %= all;
        vector<int> round;
        round.reserve(all);

        for (int j = 0; j < m - 1; j++) {
            round.push_back(grid[th][th + j]);
        }
        for (int i = 0; i < n - 1; i++) {
            round.push_back(grid[th + i][th + m - 1]);
        }
        for (int j = m - 1; j > 0; j--) {
            round.push_back(grid[th + n - 1][th + j]);
        }
        for (int i = n - 1; i > 0; i--) {
            round.push_back(grid[th + i][th]);
        }

        reverse(round.begin(), round.end());
        reverse(round.begin(), round.begin() + all - k);
        reverse(round.begin() + all - k, round.end());

        int idx = 0;
        for (int j = 0; j < m - 1; j++) {
            grid[th][th + j] = round[idx++];
        }
        for (int i = 0; i < n - 1; i++) {
            grid[th + i][th + m - 1] = round[idx++];
        }
        for (int j = m - 1; j > 0; j--) {
            grid[th + n - 1][th + j] = round[idx++];
        }
        for (int i = n - 1; i > 0; i--) {
            grid[th + i][th] = round[idx++];
        }
    }
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        init(grid, k);
        
        for (int th = 0; th < min(m, n) / 2; th++) {
            rotate(th);
        }
        return move(this->ans);
    }
};
