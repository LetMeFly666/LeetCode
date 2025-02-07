/*
 * @Author: LetMeFly
 * @Date: 2025-02-07 20:38:08
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-07 20:57:00
 */
package main

var directions [][]int = [][]int{
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
}

func generateMatrix(n int) [][]int {
    ans := make([][]int, n)
    for i := range ans {
        ans[i] = make([]int, n)
    }
    d, x, y := 0, 0, 0
    for i := 1; i <= n * n; i++ {
        ans[x][y] = i
        nx, ny := x + directions[d][0], y + directions[d][1]
        if nx == n || nx < 0 || ny == n || ny < 0 || ans[nx][ny] > 0 {
            d = (d + 1) % 4
            nx, ny = x + directions[d][0], y + directions[d][1]
        }
        x, y = nx, ny
    }
    return ans
}