/*
 * @Author: LetMeFly
 * @Date: 2024-08-29 23:19:50
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-08-29 23:26:11
 */
package main

func satisfiesConditions(grid [][]int) bool {
    for j := range grid[0] {
        if j > 0 && grid[0][j] == grid[0][j - 1] {
            return false
        }
        for i := 1; i < len(grid); i++ {
            if grid[i][j] != grid[i - 1][j] {
                return false
            }
        }
    }
    return true
}