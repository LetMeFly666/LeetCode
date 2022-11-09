/*
 * @Author: LetMeFly
 * @Date: 2022-07-12 10:01:53
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-12 10:25:14
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#else
#define dbg(x) cout << #x << " = " << x << endl
#endif

class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int> cols(m, 0);
        vector<int> rows(n, 0);
        for (auto& v : indices) {
            cols[v[0]]++;
            rows[v[1]]++;
        }
        int jiCol = 0;
        int jiRow = 0;
        for (int i = 0; i < m; i++) {
            if (cols[i] % 2)
                jiCol++;
        }
        for (int i = 0; i < n; i++) {
            if (rows[i] % 2)
                jiRow++;
        }
        int ouCol = m - jiCol;
        int ouRow = n - jiRow;
        return jiCol * ouRow + ouCol * jiRow;
    }
};