/*
 * @Author: ChatGPT
 * @Date: 2026-05-09 22:41:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-05-09 22:42:01
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int n, m, k;
    vector<vector<int>> grid;

    void init(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        this->grid = move(grid);
        this->k = k;
    }

    pair<int, int> locate(int th, int idx) {
        int m = this->m - 2 * th;
        int n = this->n - 2 * th;

        int top = th;
        int bottom = th + n - 1;
        int left = th;
        int right = th + m - 1;

        // 上
        if (idx < m - 1) {
            return {top, left + idx};
        }
        idx -= m - 1;

        // 右
        if (idx < n - 1) {
            return {top + idx, right};
        }
        idx -= n - 1;

        // 下
        if (idx < m - 1) {
            return {bottom, right - idx};
        }
        idx -= m - 1;

        // 左
        return {bottom - idx, left};
    }

    void reverse(int th, int l, int r) {
        while (l < r) {
            auto [x1, y1] = locate(th, l);
            auto [x2, y2] = locate(th, r);
            swap(grid[x1][y1], grid[x2][y2]);
            l++;
            r--;
        }
    }

    void rotate(int th) {
        int m = this->m - 2 * th;
        int n = this->n - 2 * th;

        int all = (m + n) * 2 - 4;
        int k = this->k % all;

        // 左轮转k次
        reverse(th, 0, all - 1);
        reverse(th, 0, all - k - 1);
        reverse(th, all - k, all - 1);
    }

public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        init(grid, k);
        
        for (int th = 0; th < min(m, n) / 2; th++) {
            rotate(th);
        }

        return move(this->grid);
    }
};
