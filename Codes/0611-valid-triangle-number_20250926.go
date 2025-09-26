/*
 * @Author: LetMeFly
 * @Date: 2025-09-26 22:40:03
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-26 22:49:15
 */
package main

import "sort"

func triangleNumber(nums []int) (ans int) {
    sort.Ints(nums)
    for i := len(nums) - 1; i >= 0; i-- {
        for l, r := 0, i - 1; l < r; {
            if nums[l] + nums[r] > nums[i] {
                ans += r - l
                r--
            } else {
                l++
            }
        }
    }
    return
}