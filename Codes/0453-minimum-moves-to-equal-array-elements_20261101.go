/*
 * @Author: LetMeFly
 * @Date: 2026-11-01 10:57:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-11-01 10:59:44
 */
package main

func minMoves(nums []int) (ans int) {
	m := nums[0]
	for _, t := range nums {
		m = min(t, m)
	}
	for _, t := range nums {
		ans += t - m
	}
	return
}
