/*
 * @Author: LetMeFly
 * @Date: 2025-10-14 20:14:45
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-14 20:26:58
 */
package main


func isOk3349(nums []int, i, k int) bool {
    for j := 0; j + 1 < k; j++ {
        if nums[i + j] >= nums[i + j + 1] {
            return false
        }
    }
    return true
}

func hasIncreasingSubarrays(nums []int, k int) bool {
    for i := 0; i + 2 * k <= len(nums); i++ {
        if isOk3349(nums, i, k) && isOk3349(nums, i + k, k) {
            return true
        }
    }
    return false
}