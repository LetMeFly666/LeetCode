/*
 * @Author: LetMeFly
 * @Date: 2025-04-29 13:20:02
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-29 13:23:23
 */
package main

func countSubarrays(nums []int, k int) (ans int64) {
    M := nums[0]
	for _, t := range nums {
		M = max(M, t)
	}
	for l, r, cnt := 0, 0, 0; r < len(nums); r++ {
		if nums[r] == M {
			cnt++
		}
		for cnt >= k {
			if nums[l] == M {
				cnt -= 1
			}
			l++
		}
		ans += int64(l)
	}
	return
}