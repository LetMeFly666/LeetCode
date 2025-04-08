/*
 * @Author: LetMeFly
 * @Date: 2025-04-08 21:59:54
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-08 22:01:57
 */
package main

func minimumOperations(nums []int) int {
    se := map[int]struct{}{}
    for i := len(nums) - 1; i >= 0; i-- {
        if _, ok := se[nums[i]]; ok {
            return i / 3 + 1
        }
        se[nums[i]] = struct{}{}
    }
    return 0
}