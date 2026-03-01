/*
 * @Author: LetMeFly
 * @Date: 2026-03-01 19:50:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-03-01 20:10:52
 */
package main

// 要的是max不是min别搞错了
func max1689(a, b rune) rune {
    if a < b {
        return b
    }
    return a
}

func minPartitions(n string) int {
    m := rune('0')
    for _, c := range n {
        m = max1689(m, c)
    }
    return int(byte(m) - '0')
}