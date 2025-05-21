/*
 * @Author: LetMeFly
 * @Date: 2025-05-21 23:06:35
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-21 23:23:00
 */
package main

func isZeroArray(nums []int, queries [][]int) bool {
    diff := make([]int, len(nums) + 1)
    for _, q := range queries {
        diff[q[0]]++
        diff[q[1] + 1]--
    }
    cnt := 0
    for i := 0; i < len(nums); i++ {
        cnt += diff[i]
        if nums[i] > cnt {
            return false
        }
    }
    return true
}