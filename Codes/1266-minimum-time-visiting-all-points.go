/*
 * @Author: LetMeFly
 * @Date: 2026-01-12 23:24:06
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-12 23:35:23
 */
package main

func abs1266(a int) int {
    if a < 0 {
        return -a
    }
    return a
}

func minTimeToVisitAllPoints(points [][]int) (ans int) {
    for i := 1; i < len(points); i++ {
        ans += max(abs1266(points[i][0] - points[i - 1][0]), abs1266(points[i][1] - points[i - 1][1]))
    }
    return
}