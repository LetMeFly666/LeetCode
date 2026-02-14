/*
 * @Author: LetMeFly
 * @Date: 2026-02-14 09:35:27
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-14 09:44:57
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> tower(query_row + 1);
        tower[0].resize(1);
        tower[0][0] = poured;
        for (int i = 0; i < query_row; i++) {
            tower[i + 1].resize(i + 2);
            for (int j = 0; j <= i; j++) {
                if (tower[i][j] <= 1) {
                    continue;
                }
                double half_more = (tower[i][j] - 1) / 2;
                tower[i + 1][j] += half_more;
                tower[i + 1][j + 1] += half_more;
            }
        }
        return min(1., tower[query_row][query_glass]);
    }
};