/*
 * @Author: LetMeFly
 * @Date: 2026-01-02 17:37:13
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-02 17:40:00
 */
package main

import "math/rand"

func repeatedNTimes(nums []int) int {
    n := len(nums)
    for true {
        l1 := rand.Intn(n)
        l2 := rand.Intn(n)
        if l1 != l2 && nums[l1] == nums[l2] {
            return nums[l1]
        }
    }
    return -1  // FAKE RETURN
}