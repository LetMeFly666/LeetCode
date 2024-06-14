/*
 * @Author: LetMeFly
 * @Date: 2024-06-14 19:07:00
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-14 19:13:41
 */
package main

func max(a int64, b int64) int64 {
    if a > b {
        return a
    }
    return b
}

func maxScore(nums []int, x int) int64 {
    odd, even := int64(0), int64(0)
    if nums[0] % 2 == 0 {
        odd = -int64(x)
    } else {
        even = -int64(x)
    }
    for _, t := range nums {
        if t % 2 != 0 {
            odd = max(odd + int64(t), even + int64(t) - int64(x))
        } else {
            even =  max(odd + int64(t) - int64(x), even + int64(t))
        }
    }
    return max(odd, even)
}