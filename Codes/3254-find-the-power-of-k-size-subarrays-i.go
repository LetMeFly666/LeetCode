/*
 * @Author: LetMeFly
 * @Date: 2024-11-06 17:18:41
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-06 17:26:16
 */
package main

func resultsArray(nums []int, k int) (ans []int) {
    ans = make([]int, len(nums) - k + 1)
    for i := 0; i + k <= len(nums); i++ {
        for j := i + 1; j < i + k; j++ {
            if nums[j] != nums[j - 1] + 1 {
                ans[i] = -1
                break
            }
        }
        if (ans[i] != -1) {
            ans[i] = nums[i + k - 1]
        }
    }
    return
}