/*
 * @Author: LetMeFly
 * @Date: 2026-09-05 08:24:28
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-05 08:45:09
 */
package main

func firstStableIndex(nums []int, k int) int {
	n := len(nums)
	mini := make([]int, n)
	mini[n - 1] = nums[n - 1]
	for i := n - 2; i >= 0; i-- {
		mini[i] = min(mini[i + 1], nums[i])
	}
	M := 0
	for i, t := range nums {
		M = max(M, t)
		if M - mini[i] <= k {
			return i
		}
	}
	return -1
}
