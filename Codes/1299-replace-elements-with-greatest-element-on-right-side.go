/*
 * @Author: LetMeFly
 * @Date: 2025-02-16 10:21:19
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-16 10:26:54
 */
package main

func max_REWGEORS(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func replaceElements(arr []int) []int {
    M := -1
    for i := len(arr) - 1; i >= 0; i-- {
        nM := max_REWGEORS(arr[i], M)
        arr[i] = M
        M = nM
    }
    return arr
}