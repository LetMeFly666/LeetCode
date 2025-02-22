/*
 * @Author: LetMeFly
 * @Date: 2025-02-22 11:16:35
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-22 11:27:11
 */
package main


func code_CPOSS(s string) (ans int) {
    for _, c := range s {
        ans |= 1 << (c - 'a')
    }
    return
}

func similarPairs(words []string) (ans int) {
    ma := map[int]int{}
    for _, s := range words {
        c := code_CPOSS(s)
        ans += ma[c]
        ma[c]++
    }
    return
}