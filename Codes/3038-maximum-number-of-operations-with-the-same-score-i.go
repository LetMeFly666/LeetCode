/*
 * @Author: LetMeFly
 * @Date: 2024-06-07 20:24:47
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-07 20:25:52
 */
package main

func maxOperations(nums []int) int {
    ans := 1
    val := nums[0] + nums[1]
    for i := 2; i < len(nums)-1; i += 2 {
        if nums[i]+nums[i+1] != val {
            break
        }
        ans++
    }
    return ans
}