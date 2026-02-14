/*
 * @Author: LetMeFly
 * @Date: 2026-02-14 10:04:41
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-14 10:07:43
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double row1[query_row + 1], row2[query_row + 1];
        row1[0] = poured;
        for (int i = 0; i < query_row; i++) {
            double half_more = (row1[i] - 1) / 2;
            row2[i] += half_more;
            row2[i + 1] += half_more;
            swap(row1, row2);
            memset(row2, 0, sizeof(row2));
        }
        return row1[query_row][query_glass];
    }
};