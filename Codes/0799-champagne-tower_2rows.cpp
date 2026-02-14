/*
 * @Author: LetMeFly
 * @Date: 2026-02-14 10:04:41
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-14 10:22:09
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double *row1 = new double[query_row + 1], *row2 = new double[query_row + 1];
        row1[0] = poured;
        for (int i = 0; i < query_row; i++) {
            memset(row2, 0, sizeof(double) * (query_row + 1));
            double half_more = (row1[i] - 1) / 2;
            row2[i] += half_more;
            row2[i + 1] += half_more;
            swap(row1, row2);
        }
        return min(1., row1[query_glass]);  // didn't delete
    }
};

#if defined(_WIN32) || defined(__APPLE__)
/*
25 6 1
*/
int main() {
    int a, b, c;
    while (cin >> a >> b >> c) {
        Solution sol;
        cout << sol.champagneTower(a, b, c) << endl;
    }
    return 0;
}
#endif