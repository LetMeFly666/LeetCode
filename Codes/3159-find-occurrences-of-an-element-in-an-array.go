/*
 * @Author: LetMeFly
 * @Date: 2024-12-27 12:22:32
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-27 12:23:51
 */
package main

func occurrencesOfElement(nums []int, queries []int, x int) []int {
    locs := make([]int, 0)
    for i, v := range nums {
        if v == x {
            locs = append(locs, i)
        }
    }
    ans := make([]int, 0)
    for _, q := range queries {
        if q > len(locs) {
            ans = append(ans, -1)
        } else {
            ans = append(ans, locs[q - 1])
        }
    }
    return ans
}