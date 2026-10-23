/*
 * @Author: LetMeFly
 * @Date: 2026-10-23 20:28:52
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-23 20:33:11
 */
package main

func sortPermutation(nums []int) int {
	if nums[0] != 0 {
		return 0
	}
	ans := -1
	for i, t := range nums {
		if t != i {
			ans &= i
		}
	}
	return max(ans, 0)
}
