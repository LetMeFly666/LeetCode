/*
 * @Author: LetMeFly
 * @Date: 2026-04-13 21:39:33
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-04-13 21:44:01
 */
package main

func abs1848(a int) int {
	if a >= 0 {
		return a
	}
	return -a
}

func getMinDistance(nums []int, target int, start int) int {
	ans := len(nums)
	for i, v := range nums {
		if v == target {
			ans = min(ans, abs1848(i - start))
		}
	}
	return ans
}
