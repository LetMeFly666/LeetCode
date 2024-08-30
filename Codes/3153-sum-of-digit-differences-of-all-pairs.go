/*
 * @Author: LetMeFly
 * @Date: 2024-08-30 22:00:44
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-08-30 22:16:14
 */
package main

func sumDigitDifferences(nums []int) int64 {
    ans := int64(0)
    for nums[0] > 0 {
        times := make([]int, 10)
        for i, n := range nums {
            times[n % 10]++
            nums[i] /= 10
        }
        for i := 0; i < 10; i++ {
            ans += int64(times[i] * (len(nums) - times[i]))
        }
    }
    return ans / 2
}