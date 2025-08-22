/*
 * @Author: LetMeFly
 * @Date: 2025-08-22 21:18:33
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-22 21:30:00
 */
package main

func minimumArea(grid [][]int) int {
    l, r, u, d := 1000, 0, 1000, 0
    for i, row := range grid {
        for j, g := range row {
            if g == 1 {
                l = min(l, j)
                r = max(r, j)
                u = min(u, i)
                d = max(d, i)
            }
        }
    }
    return (r - l + 1) * (d - u + 1)
}