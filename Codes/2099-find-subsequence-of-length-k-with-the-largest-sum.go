/*
 * @Author: LetMeFly
 * @Date: 2025-07-03 21:31:48
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-06 22:08:12
 */
package main

import "sort"

func maxSubsequence(nums []int, k int) []int {
    idx := make([]int, len(nums))
    for i := range idx {
        idx[i] = i
    }
    sort.Slice(idx, func(i, j int) bool {
        return nums[i] > nums[j] 
    })
    idx = idx[:k]
    sort.Ints(idx)
    for th, i := range idx {
        idx[th] = nums[i]
    }
    return idx
}