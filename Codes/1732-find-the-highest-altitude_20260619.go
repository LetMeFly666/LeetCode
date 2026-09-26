/*
 * @Author: LetMeFly
 * @Date: 2026-06-19 10:15:51
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-06-19 10:17:13
 */
package main

func largestAltitude(gain []int) (ans int) {
	now := 0
	for _, t := range gain {
		now += t
		ans = max(ans, now)
	}
	return
}
