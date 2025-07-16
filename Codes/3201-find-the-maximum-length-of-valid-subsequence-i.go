/*
 * @Author: LetMeFly
 * @Date: 2025-07-16 13:16:29
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-16 13:40:18
 */
package main

func maximumLength(nums []int) (ans int) {
    odd := 0
    last := nums[0] % 2 == 0
    for _, t := range nums {
        if t % 2 == 0 {
            if last {
                last = false
                ans++
            }
        } else {
            odd++
            if !last {
                last = true
                ans++
            }
        }
    }
    return max(ans, max(odd, len(nums) - odd))
}