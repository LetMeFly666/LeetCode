/*
 * @Author: LetMeFly
 * @Date: 2024-11-15 12:51:26
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-15 12:54:08
 */
package main

func forLine(grid [][]int) (ans int) {
    n, m := len(grid), len(grid[0])
    for i := 0; i < n; i++ {
        for j := 0; j < m / 2; j++ {
            if grid[i][j] != grid[i][m - j - 1] {
                ans++
            }
        }
    }
    return
}

func forCol(grid [][]int) (ans int) {
    n, m := len(grid), len(grid[0])
    for j := 0; j < m; j++ {
        for i := 0; i < n / 2; i++ {
            if grid[i][j] != grid[n - i - 1][j] {
                ans++
            }
        }
    }
    return
}

func minFlips(grid [][]int) int {
    return min(forLine(grid), forCol(grid))
}