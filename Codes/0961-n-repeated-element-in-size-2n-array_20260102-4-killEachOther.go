/*
 * @Author: LetMeFly
 * @Date: 2026-01-02 17:33:33
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-02 17:36:18
 */
package main

func repeatedNTimes(nums []int) int {
    ans, hp := -1, 0
    for i := 1; i < len(nums); i++ {
        if nums[i] == nums[0] {
            return nums[0]
        }
        if hp == 0 {
            ans, hp = nums[i], 1
        } else if ans == nums[i] {
            hp++
        } else {
            hp--
        }
    }
    return ans
}