/*
 * @Author: LetMeFly
 * @Date: 2025-01-13 22:37:03
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-13 22:39:18
 */
package main

func waysToSplitArray(nums []int) (ans int) {
    prefix := make([]int, len(nums))
    prefix[0] = nums[0]
    for i := 1; i < len(nums); i++ {
        prefix[i] = prefix[i - 1] + nums[i]
    }
    for i := 0; i < len(nums) - 1; i++ {
        if prefix[i] >= prefix[len(nums) - 1] - prefix[i] {
            ans++
        }
    }
    return
}