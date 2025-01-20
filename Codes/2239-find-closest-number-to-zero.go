/*
 * @Author: LetMeFly
 * @Date: 2025-01-20 13:34:23
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-20 16:00:01
 */
package main

func abs(a int) int {
    if a < 0 {
        return -a
    }
    return a
}

func findClosestNumber(nums []int) int {
    ans := nums[0]
    for _, t := range nums {
        if abs(t) < abs(ans) || abs(t) == abs(ans) && ans < 0 {
            ans = t
        }
    }
    return ans
}