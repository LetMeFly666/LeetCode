/*
 * @Author: LetMeFly
 * @Date: 2025-05-24 21:30:36
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-24 21:40:52
 */
package main

import "strings"

func findWordsContaining(words []string, x byte) (ans []int) {
    for i, word := range words {
        if strings.IndexByte(word, x) >= 0 {
            ans = append(ans, i)
        }
    }
    return
}