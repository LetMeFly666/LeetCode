/*
 * @Author: LetMeFly
 * @Date: 2025-02-08 09:55:20
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-08 10:02:07
 */
class Solution {
    public int uniquePathsWithObstacles(int[][] a) {
        if (a[0][0] == 1) {
            return 0;
        }
        a[0][0] = 1;
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[0].length; j++) {
                if (a[i][j] == 1 && i + j > 0) {
                    a[i][j] = 0;
                    continue;
                }
                if (i > 0) {
                    a[i][j] += a[i - 1][j];
                }
                if (j > 0) {
                    a[i][j] += a[i][j - 1];
                }
            }
        }
        return a[a.length - 1][a[0].length - 1];
    }
}