/*
 * @Author: LetMeFly
 * @Date: 2026-01-05 13:31:38
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-05 18:45:13
 */
package main

func abs1975(a int) int {
    if a < 0 {
        return -a
    }
    return a
}

func maxMatrixSum(matrix [][]int) (ans int64) {
    cnt, mini := 0, 1000000
    for _, row := range matrix {
        for _, t := range row {
            if t < 0 {
                cnt++
            }
            t = abs1975(t)
            ans += int64(t)
            mini = min(mini, t)
        }
    }
    if cnt % 2 == 1 {
        ans -= 2 * int64(mini)
    }
    return
}