/*
 * @Author: LetMeFly
 * @Date: 2025-10-31 22:19:33
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-31 22:24:27
 */
package main

func getSneakyNumbers(nums []int) (ans []int) {
    se := map[int]struct{}{}
    for _, t := range nums {
        if _, ok := se[t]; ok {
            ans = append(ans, t)
        } else {
            se[t] = struct{}{}
        }
    }
    return
}