/*
 * @Author: LetMeFly
 * @Date: 2025-07-03 21:31:48
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-06 22:16:49
 */
package main

import "sort"

func maxSubsequence(nums []int, k int) []int {
    idx := make([]int, len(nums))
    for i := range idx {
        idx[i] = i
    }
    sort.Slice(idx, func(i, j int) bool {
        return nums[idx[i]] > nums[idx[j]]  // 不可以nums[i] > nums[j]，因为排序过程中idx[i]可能不再是i 
    })
    idx = idx[:k]
    sort.Ints(idx)
    for th, i := range idx {
        idx[th] = nums[i]
    }
    return idx
}