/*
 * @Author: LetMeFly
 * @Date: 2025-04-24 22:47:30
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-24 23:22:04
 */
package main

func countCompleteSubarrays(nums []int) (ans int) {
    visited := map[int]bool{}
	for _, t := range nums {
		visited[t] = true
	}
	allType := len(visited)
	times := map[int]int{}
	l := 0
	for _, t := range nums {
		times[t]++
		for len(times) == allType && times[nums[l]] > 1 {
			times[nums[l]]--
			l++
		}
		if len(times) == allType {
			ans += l + 1
		}
	}
	return
}