/*
 * @Author: LetMeFly
 * @Date: 2025-06-10 23:07:14
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-10 23:20:56
 */
package main

func maxDifference(s string) int {
    cnt := [26]int{}
    for _, c := range s {
        cnt[c - 'a']++
    }
    a1, a2 := 0, 100
    for _, t := range cnt {
        if t % 2 == 1 {
            a1 = max(a1, t)
        } else if t > 0 {
            a2 = min(a2, t)
        }
    }
    return a1 - a2
}