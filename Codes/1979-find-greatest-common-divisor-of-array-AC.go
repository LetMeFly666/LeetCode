/*
 * @Author: LetMeFly
 * @Date: 2026-07-18 07:00:55
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-18 07:10:26
 */
package main

func gcd1979(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd1979(b, a % b)
}

func findGCD(nums []int) int {
	m := nums[0]
	M := m
	for _, t := range nums {
		m = min(m, t)
		M = max(M, t)
	}
	return gcd1979(M, m)
}
