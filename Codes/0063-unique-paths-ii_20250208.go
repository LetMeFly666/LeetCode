/*
 * @Author: LetMeFly
 * @Date: 2025-02-08 09:55:29
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-08 10:04:49
 */
package main

func uniquePathsWithObstacles(a [][]int) int {
    if a[0][0] == 1 {
        return 0
    }
    a[0][0] = 1
    for i := range a {
        for j := range a[0] {
            if a[i][j] == 1 && i + j > 0 {
                a[i][j] = 0
                continue
            }
            if i > 0 {
                a[i][j] += a[i - 1][j]
            }
            if j > 0 {
                a[i][j] += a[i][j - 1]
            }
        }
    }
    return a[len(a) - 1][len(a[0]) - 1]
}