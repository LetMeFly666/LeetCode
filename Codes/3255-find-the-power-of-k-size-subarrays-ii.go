/*
 * @Author: LetMeFly
 * @Date: 2024-11-07 12:30:34
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-07 12:34:14
 */
package main

func resultsArray(nums []int, k int) (ans []int) {
    ans = make([]int, len(nums) - k + 1)
    notContinue := 0
    for i := 1; i < k; i++ {
        if nums[i] != nums[i - 1] + 1 {
            notContinue++
        }
    }
    if notContinue > 0 {
        ans[0] = -1
    } else {
        ans[0] = nums[k - 1]
    }
    for i := 1; i + k <= len(nums); i++ {
        if nums[i] != nums[i - 1] + 1 {
            notContinue--
        }
        if nums[i + k - 1] != nums[i + k - 2] + 1 {
            notContinue++
        }
        if notContinue > 0 {
            ans[i] = -1
        } else {
            ans[i] = nums[i + k - 1]
        }
    }
    return
}