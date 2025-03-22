/*
 * @Author: LetMeFly
 * @Date: 2025-03-22 22:49:36
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-22 22:50:36
 */
class Solution {
    public int[] rowAndMaximumOnes(int[][] mat) {
        int ans = 0, mx = 0;
        for (int i = 0; i < mat.length; i++) {
            int cnt = 0;
            for (int j = 0; j < mat[i].length; j++) {
                cnt += mat[i][j];
            }
            if (cnt > mx) {
                mx = cnt;
                ans = i;
            }
        }
        return new int[]{ans, mx};
    }
}