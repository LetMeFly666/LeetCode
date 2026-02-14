/*
 * @Author: LetMeFly
 * @Date: 2022-11-20 11:02:03
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-11-20 11:06:57
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double glass[100][100];
        glass[0][0] = poured;
        for (int i = 1; i <= query_row; i++) {
            for (int j = 0; j <= query_glass; j++) {
                if (j == 0) {
                    glass[i][j] = max((double)0, (glass[i - 1][j] - 1) / 2);
                }
                else {
                    glass[i][j] = max((double)0, (glass[i - 1][j] - 1) / 2) + max((double)0, (glass[i - 1][j - 1] - 1) / 2);
                }
            }
        }
        return min((double)1, glass[query_row][query_glass]);
    }
};