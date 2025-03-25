/*
 * @Author: LetMeFly
 * @Date: 2025-03-25 21:29:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-25 21:37:43
 */
package main

import "math/bits"

func abs2711(a int) int {
    if a < 0 {
        return -a
    }
    return a
}

func differenceOfDistinctValues(grid [][]int) [][]int {
    n, m := len(grid), len(grid[0])
    ans := make([][]int, n)
    for i := range ans {
        ans[i] = make([]int, m)
    }
    for k := 0; k < m + n - 1; k++ {
        var i, j int
        if k < m {
            i, j = 0, k
        } else {
            i, j = k - m + 1, 0
        }
        se := uint64(0)
        d := 0
        for ; i + d < n && j + d < m; d++ {
            ans[i + d][j + d] = bits.OnesCount64(se)
            se |= uint64(1) << grid[i + d][j + d]
        }
        se = 0
        for d--; d >= 0; d-- {
            ans[i + d][j + d] = abs2711(ans[i + d][j + d] - bits.OnesCount64(se))
            se |= uint64(1) << grid[i + d][j + d]
        }
    }
    return ans
}