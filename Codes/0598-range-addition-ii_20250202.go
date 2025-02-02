/*
 * @Author: LetMeFly
 * @Date: 2025-02-02 11:09:24
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-02 11:10:27
 */
package main

func min_RA2(m, n int) int {
    if m < n {
        return m
    }
    return n
}

func maxCount(m int, n int, ops [][]int) int {
    for _, op := range ops {
        m = min_RA2(m, op[0])
        n = min_RA2(n, op[1])
    }
    return m * n
}