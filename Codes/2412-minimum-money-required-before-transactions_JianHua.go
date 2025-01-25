/*
 * @Author: LetMeFly
 * @Date: 2025-01-25 10:07:19
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-25 10:12:39
 */
package main

func max_MMRBT[T int](a T, b T) T {
    if a > b {
        return a
    }
    return b
}

func min_MMRBT(a int, b int) int {
    if a < b {
        return a
    }
    return b
}

func minimumMoney(transactions [][]int) (ans int64) {
    M := 0
    for _, t := range transactions {
        ans += int64(max_MMRBT(0, t[0] - t[1]))
        M = max_MMRBT(M, min_MMRBT(t[0], t[1]))
    }
    ans += int64(M)
    return
}