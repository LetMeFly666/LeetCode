/*
 * @Author: LetMeFly
 * @Date: 2026-01-20 22:50:06
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-20 22:58:16
 */
package main

func minBitwiseArray(nums []int) []int {
    get := func(n int) int {
        for i := 0; i < n; i++ {
            if (i | (i + 1)) == n {
                return i
            }
        }
        return -1
    }
    ans := make([]int, len(nums))
    for i, n := range nums {
        ans[i] = get(n)
    }
    return ans
}