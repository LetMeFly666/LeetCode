/*
 * @Author: LetMeFly
 * @Date: 2024-12-11 23:22:18
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-11 23:23:28
 */
package main

func semiOrderedPermutation(nums []int) (ans int) {
    a, b := 0, 0
    for th, val := range nums {
        if val == 1 {
            a = th
        } else if val == len(nums) {
            b = th
        }
    }
    ans = a + (len(nums) - b - 1)
    if a > b {
        ans--
    }
    return
}