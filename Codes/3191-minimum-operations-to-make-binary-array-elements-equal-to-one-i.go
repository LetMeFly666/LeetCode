/*
 * @Author: LetMeFly
 * @Date: 2024-10-18 23:06:33
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-18 23:08:12
 */
package main

func minOperations(nums []int) int {
    ans := 0
    for i := 0; i < len(nums) - 2; i++ {
        if nums[i] == 0 {
            ans++
            nums[i + 1] ^= 1
            nums[i + 2] ^= 1
        }
    }
    if nums[len(nums) - 1] & nums[len(nums) - 2] == 1 {
        return ans
    } else {
        return -1
    }
}