/*
 * @Author: LetMeFly
 * @Date: 2025-09-25 23:12:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-25 23:26:32
 */
package main

func minimumTotal(triangle [][]int) int {
    for i := len(triangle) - 2; i >= 0; i-- {
        for j := 0; j <= i; j++ {
            triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1])
        }
    }
    return triangle[0][0]
}