/*
 * @Author: LetMeFly
 * @Date: 2025-11-14 19:38:51
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-11-14 19:42:41
 */
package main

func rangeAddQueries(n int, queries [][]int) [][]int {
    diff := make([][]int, n + 1)
    for i := range diff {
        diff[i] = make([]int, n + 1)
    }
    for _, q := range queries {
        x1, y1, x2, y2 := q[0], q[1], q[2], q[3]
        diff[x1][y1]++
        diff[x2 + 1][y1]--
        diff[x1][y2 + 1]--
        diff[x2 + 1][y2 + 1]++
    }

    ans := make([][]int, n)
    for i := range ans {
        ans[i] = make([]int, n)
    }
    for i := range ans {
        for j := range ans[i] {
            up := 0
            if i > 0 {
                up = diff[i - 1][j]
            }
            left := 0
            if j > 0 {
                left = diff[i][j - 1]
            }
            lu := 0
            if i > 0 && j > 0 {
                lu = diff[i - 1][j - 1]
            }
            ans[i][j] = diff[i][j] - left - up + lu
        }
    }
    return ans
}