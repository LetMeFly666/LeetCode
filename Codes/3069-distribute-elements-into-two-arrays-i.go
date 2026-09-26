/*
 * @Author: LetMeFly
 * @Date: 2026-08-20 10:12:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-08-20 10:27:19
 */
package main

func resultArray(nums []int) []int {
	v1 := []int{nums[0]}
	v2 := []int{nums[1]}
	for i, n := 2, len(nums); i < n; i++ {
		if v1[len(v1)-1] > v2[len(v2)-1] {
			v1 = append(v1, nums[i])
		} else {
			v2 = append(v2, nums[i])
		}
	}
	v1 = append(v1, v2...)
	return v1
}
