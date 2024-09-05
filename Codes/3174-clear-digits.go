/*
 * @Author: LetMeFly
 * @Date: 2024-09-05 09:31:15
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-09-05 17:12:58
 */
package main
import "unicode"

func clearDigits(s string) string {
    ansList := []rune{}
    cntDigit := 0
    for i := len(s) - 1; i >= 0; i-- {
        if unicode.IsDigit(rune(s[i])) {
            cntDigit++
        } else if cntDigit > 0 {
            cntDigit--
        } else {
            ansList = append(ansList, rune(s[i]))
        }
    }
    for i := 0; i < len(ansList) / 2; i++ {
        ansList[i], ansList[len(ansList) - i - 1] = ansList[len(ansList) - i - 1], ansList[i]
    }
    return string(ansList)
}