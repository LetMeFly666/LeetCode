/*
 * @Author: LetMeFly
 * @Date: 2024-06-23 19:04:00
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-23 19:08:14
 */
package main

import "unicode"

func detectCapitalUse(word string) bool {
    cntLower := 0
    for i := 1; i < len(word); i++ {
        if unicode.IsLower(rune(word[i])) {
            cntLower++
        }
    }
    return cntLower == len(word) - 1 || cntLower == 0 && unicode.IsUpper(rune(word[0]))
}