/*
 * @Author: LetMeFly
 * @Date: 2025-03-17 12:20:26
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-17 12:21:31
 */
package main

func minSwaps(s string) int {
    zuoQianYou, zuo := 0, 0
    for i := range s {
        if s[i] == '[' {
            zuo++
        } else {
            if zuo > 0 {
                zuo--
            } else {
                zuoQianYou++
            }
        }
    }
    return (zuoQianYou + 1) / 2
}