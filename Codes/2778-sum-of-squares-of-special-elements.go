/*
 * @Author: LetMeFly
 * @Date: 2026-10-11 09:02:48
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-11 09:05:38
 */
package main

func sumOfSquares(nums []int) (ans int) {
	for i, t := range nums {
		if len(nums) % (i + 1) == 0 {
			ans += t * t
		}
	}
	return
}
