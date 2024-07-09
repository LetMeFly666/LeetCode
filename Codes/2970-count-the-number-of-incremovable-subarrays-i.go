/*
 * @Author: LetMeFly
 * @Date: 2024-07-10 00:24:05
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-10 00:24:10
 */
package main

func isOk(nums []int, l int, r int) int {
    last := 0
    for i := 0; i < len(nums); i++ {
        if l <= i && i <= r {
            continue
        }
        if nums[i] <= last {
            return 0
        }
        last = nums[i]
    }
    return 1
}

func incremovableSubarrayCount(nums []int) int {
    ans := 0
    for l := 0; l < len(nums); l++ {
        for r := l; r < len(nums); r++ {
            ans += isOk(nums, l, r)
        }
    }
    return ans
}