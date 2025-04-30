/*
 * @Author: LetMeFly
 * @Date: 2025-04-29 23:46:45
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-30 10:55:53
 */
package main

func countSubarrays(nums []int, k int64) (ans int64) {
    cnt := int64(0)
    l := 0
    for r, t := range nums {
        cnt += int64(t)
        for cnt * int64(r - l + 1) >= k {
            cnt -= int64(nums[l])
            l++
        }
        ans += int64(r - l + 1)
    }
    return
}