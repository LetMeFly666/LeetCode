/*
 * @Author: LetMeFly
 * @Date: 2025-03-24 17:55:08
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-24 17:55:24
 */
package main

import "strings"

func countPrefixes(words []string, s string) (ans int) {
    for _, word := range words {
        if strings.HasPrefix(s, word) {
            ans++
        }
    }
    return
}