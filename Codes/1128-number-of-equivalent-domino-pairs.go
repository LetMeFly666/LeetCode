/*
 * @Author: LetMeFly
 * @Date: 2025-05-04 14:26:18
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-04 16:18:34
 */
package main

func numEquivDominoPairs(dominoes [][]int) (ans int) {
    times := make([]int, 81)
    for _, d := range dominoes {
        var v int
        if d[0] < d[1] {
            v = (d[0] - 1) * 9 + d[1] - 1
        } else {
            v = (d[1] - 1) * 9 + d[0] - 1
        }
        ans += times[v]
        times[v]++
    }
    return
}