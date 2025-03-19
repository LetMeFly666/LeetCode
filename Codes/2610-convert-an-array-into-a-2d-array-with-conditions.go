/*
 * @Author: LetMeFly
 * @Date: 2025-03-19 20:03:37
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-19 20:05:02
 */
package main

func findMatrix(nums []int) (ans [][]int) {
    ma := map[int]int{}
    for _, t := range nums {
        ma[t]++
        if ma[t] > len(ans) {
            ans = append(ans, make([]int, 0))
        }
        ans[ma[t] - 1] = append(ans[ma[t]-1], t)
    }
    return
}