/*
 * @Author: LetMeFly
 * @Date: 2024-07-05 21:43:49
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-05 21:44:54
 */
class Solution {
    public int[][] modifiedMatrix(int[][] matrix) {
        for (int j = 0; j < matrix[0].length; j++) {
            int M = matrix[0][j];
            for (int i = 1; i < matrix.length; i++) {
                M = Math.max(M, matrix[i][j]);
            }
            for (int i = 0; i < matrix.length; i++) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = M;
                }
            }
        }
        return matrix;
    }
}