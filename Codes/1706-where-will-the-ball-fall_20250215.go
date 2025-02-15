/*
 * @Author: LetMeFly
 * @Date: 2025-02-15 11:21:06
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-15 11:27:19
 */
package main

func drop_WWTBF(grid [][]int, y int) int {
    for x := range grid {
        nextY := y + grid[x][y]
        if nextY < 0 || nextY >= len(grid[0]) || grid[x][y] != grid[x][nextY] {
            return -1
        }
        y = nextY
    }
    return y
}

func findBall(grid [][]int) []int {
    ans := make([]int, len(grid[0]))
    for j := range grid[0] {
        ans[j] = drop_WWTBF(grid, j)
    }
    return ans
}