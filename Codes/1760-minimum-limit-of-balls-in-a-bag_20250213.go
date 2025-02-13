/*
 * @Author: LetMeFly
 * @Date: 2025-02-13 13:43:12
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-13 13:51:10
 */
package main

import "slices"

func check_MLBI1B(nums []int, op, m int) bool {
    for _, t := range nums {
        op -= (t - 1) / m
    }
    return op >= 0
}

func minimumSize(nums []int, maxOperations int) int {
    l, r := 1, slices.Max(nums)
    for l < r {
        m := (l + r) >> 1
        if check_MLBI1B(nums, maxOperations, m) {
            r = m
        } else {
            l = m + 1
        }
    }
    return r
}