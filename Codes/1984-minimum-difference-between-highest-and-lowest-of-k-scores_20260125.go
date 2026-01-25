/*
 * @Author: LetMeFly
 * @Date: 2026-01-25 10:32:52
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-25 10:39:42
 */
package main

import "sort"

// THIS CANNOT BE ACCEPTED
func minimumDifference(nums []int, k int) (ans int) {
    sort.Ints(nums)
	for i := 0; i < len(nums) - k + 1; i++ {
		ans = min(ans, nums[i + k - 1] - nums[i])
	}
	return
}