/*
 * @Author: LetMeFly
 * @Date: 2026-05-11 21:16:18
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-05-11 21:22:04
 */
package main

import "slices"

func separateDigits(nums []int) (ans []int) {
	for _, x := range slices.Backward(nums) {
		for x > 0 {
			ans = append(ans, x % 10)
			x /= 10
		}
	}
	slices.Reverse(ans)
	return
}
