/*
 * @Author: LetMeFly
 * @Date: 2025-08-25 18:56:28
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-26 00:00:06
 */
package main

func findDiagonalOrder(mat [][]int) []int {
    n, m := len(mat), len(mat[0])
    ans := make([]int, 0, m * n)
    for k := 0; k < m + n - 1; k++ {
        if k % 2 == 0 {
            i := min(k, n - 1)
            for j := k - i; i >= 0 && j < m; i, j = i - 1, j + 1 {
                ans = append(ans, mat[i][j])
            }
        } else {
            j := min(k, m - 1)
            for i := k - j; i < n && j >= 0; i, j = i + 1, j - 1 {
                ans = append(ans, mat[i][j])
            }
        }
    }
    return ans
}