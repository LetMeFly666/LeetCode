/*
 * @Author: LetMeFly
 * @Date: 2024-07-05 21:45:51
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-05 21:53:38
 */
package main
func modifiedMatrix(matrix [][]int) [][]int {
    for j := 0; j < len(matrix[0]); j++ {
        M := matrix[0][j]
        for i := 1; i < len(matrix); i++ {
            if matrix[i][j] > M {
                M = matrix[i][j]
            }
        }
        for i := 0; i < len(matrix); i++ {
            if matrix[i][j] == -1 {
                matrix[i][j] = M
            }
        }
    }
    return matrix
}