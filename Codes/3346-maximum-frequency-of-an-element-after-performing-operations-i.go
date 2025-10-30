/*
 * @Author: LetMeFly
 * @Date: 2025-10-30 22:39:36
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-30 23:00:59
 */
package main

import "sort"

func maxFrequency(nums []int, k int, numOperations int) (ans int) {
    sort.Ints(nums)
    frequency := map[int]int{}
    for _, t := range nums {
        frequency[t]++
    }
    n := len(nums)
    for l, r, target := 0, 0, nums[0]; target <= nums[n - 1]; target++ {
        for target - nums[l] > k {
            l++
        }
        for r < n && nums[r] - target <= k {
            r++
        }
        ans = max(ans, min(r - l, numOperations + frequency[target]))
    }
    return
}