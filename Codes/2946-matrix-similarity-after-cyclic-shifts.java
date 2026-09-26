/*
 * @Author: LetMeFly
 * @Date: 2026-03-27 08:48:57
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-03-27 08:57:58
 */
class Solution {
    public boolean areSimilar(int[][] mat, int k) {
        int m = mat[0].length;
        for (int[] row : mat) {
            for (int j = 0; j < m; j++) {
                if (row[j] != row[(j + k) % m]) {
                    return false;
                }
            }
        }
        return true;
    }
}