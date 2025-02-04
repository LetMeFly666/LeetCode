/*
 * @Author: LetMeFly
 * @Date: 2025-02-04 22:25:07
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-04 22:32:30
 */
package main

func sortArrayByParityII(nums []int) []int {
    for i, j := 0, 1; i < len(nums); {
		if nums[i] % 2 == 0 {
			i += 2
		} else if nums[j] % 2 == 1 {
			j += 2
		} else {
			nums[i], nums[j] = nums[j], nums[i]
			i += 2
			j += 2
		}
	}
	return nums
}