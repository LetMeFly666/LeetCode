/*
 * @Author: LetMeFly
 * @Date: 2024-08-16 00:07:40
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-08-16 00:11:15
 */
package main


func min(a int, b int) int {
    if a < b {
        return a
    }
    return b
}

func max(a int, b int) int {
    if a > b {
        return a
    }
    return b
}

func maxScore(grid [][]int) int {
    ans := -12345678
    for i, line := range grid {
        for j, item := range line {
            original := item
            if i > 0 {
                grid[i][j] = min(grid[i][j], grid[i - 1][j])  // 这里修改item的值不会改变grid[i][j]的值
                ans = max(ans, original - grid[i - 1][j])
            }
            if j > 0 {
                grid[i][j] = min(grid[i][j], grid[i][j - 1])
                ans = max(ans, original - grid[i][j - 1])
            }
        }
    }
    return ans
}