/*
 * @Author: LetMeFly
 * @Date: 2025-04-17 20:19:13
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-17 20:21:29
 */
package main

func countPairs(nums []int, k int) (ans int) {
    for i := range nums {
		for j := i + 1; j < len(nums); j++ {
			if nums[i] == nums[j] && i * j % k == 0 {
				ans++
			}
		}
	}
	return
}