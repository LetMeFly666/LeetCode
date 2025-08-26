/*
 * @Author: LetMeFly
 * @Date: 2025-08-25 18:56:28
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-26 10:20:44
 */
class Solution {
    public int[] findDiagonalOrder(int[][] mat) {
        int n = mat.length, m = mat[0].length;
        int[] ans = new int[m * n];
        for (int k = 0, cnt = 0; k < m + n - 1; k++, cnt++) {
            if (k % 2 == 0) {
                for (int i = Math.min(k, n - 1), j = k - i; i >= 0 && j < m; i--, j++) {
                    ans[cnt] = mat[i][j];
                }
            } else {
                for (int j = Math.min(k, m - 1), i = k - j; i < n && j >= 0; i++, j--) {
                    ans[cnt] = mat[i][j];
                }
            }
        }
        return ans;
    }
}