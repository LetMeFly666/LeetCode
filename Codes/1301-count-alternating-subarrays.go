/*
 * @Author: LetMeFly
 * @Date: 2024-07-06 10:47:52
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-06 10:51:17
 */
package main

func countAlternatingSubarrays(nums []int) int64 {
    var ans int64 = 0
    for from, to := 0, 1; to <= len(nums); to++ {
        if to == len(nums) || nums[to] == nums[to - 1] {
            var length int64 = int64(to - from)
            ans += (1 + length) * length / 2
            from = to
        }
    }
    return ans
}