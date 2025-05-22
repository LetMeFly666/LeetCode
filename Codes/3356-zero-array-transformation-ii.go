/*
 * @Author: LetMeFly
 * @Date: 2025-05-22 22:07:10
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-22 23:33:57
 */
package main

func check3356(nums []int, queries [][]int, n int) bool {
	diff := make([]int, len(nums) + 1)
	for _, q := range queries[:n] {
		diff[q[0]] += q[2]
		diff[q[1] + 1] -= q[2]
	}
	cnt := 0
	for i := range nums {
		cnt += diff[i]
		if nums[i] > cnt {
			return false
		}
	}
	return true
}

func minZeroArray(nums []int, queries [][]int) int {
    l, r := -1, len(queries) + 1
	for l + 1 < r {
		m := (l + r) >> 1
		if check3356(nums, queries, m) {
			r = m
		} else {
			l = m
		}
	}
	if r > len(queries) {
		return -1
	}
	return r
}