/*
 * @Author: LetMeFly
 * @Date: 2025-04-27 23:49:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-27 23:52:54
 * @Description: AC,100.00%,95.45%
 */
package main

func countSubarrays(nums []int) (ans int) {
    for i := 2; i < len(nums); i++ {
        if (nums[i] + nums[i - 2]) * 2 == nums[i - 1] {
            ans++
        }
    }
    return
}