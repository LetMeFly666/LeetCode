/*
 * @Author: LetMeFly
 * @Date: 2024-12-13 09:40:31
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-13 09:42:10
 */
package main

func getFinalState(nums []int, k int, multiplier int) []int {
    for round := 0; round < k; round++ {
        m, loc := nums[0], 0
        for i, val := range nums {
            if val < m {
                m, loc = val, i
            }
        }
        nums[loc] *= multiplier
    }
    return nums
}