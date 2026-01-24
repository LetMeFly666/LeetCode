/*
 * @Author: LetMeFly
 * @Date: 2026-01-24 09:29:52
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-24 09:34:40
 */
package main

import "sort"

func minPairSum(nums []int) (ans int) {
    sort.Ints(nums)
    for i := 0; i < len(nums) / 2; i++ {
        ans = max(ans, nums[i] + nums[len(nums) - i - 1])
    }
    return
}