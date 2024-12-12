/*
 * @Author: LetMeFly
 * @Date: 2024-12-12 14:45:31
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-12 14:49:42
 */
package main

func maxSpending(values [][]int) (ans int64) {
    loc := make([]int, len(values))
    for i := range loc {
        loc[i] = len(values[0]) - 1
    }
    cnt, th := (int64)(len(values) * len(values[0])), (int64)(1)
    for th <= cnt {
        m, mLoc := 10000000, 0
        for i := range values {
            if loc[i] >= 0 && values[i][loc[i]] < m {
                m, mLoc = values[i][loc[i]], i
            }
        }
        ans += (int64)(values[mLoc][loc[mLoc]]) * th
        th++
        loc[mLoc]--
    }
    return
}