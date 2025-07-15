/*
 * @Author: LetMeFly
 * @Date: 2025-07-15 23:15:03
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-15 23:40:26
 */
package main

func isYuan3136(c byte) bool {
    return c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u'
}

func isValid(word string) bool {
    if len(word) < 3 {
        return false
    }
    hasYuan, hasFu := false, false
    for _, c := range word {
        if 'A' <= c && c <= 'Z' {
            c += 32
        }
        if 'a' <= c && c <= 'z' {
            if isYuan3136(byte(c)) {
                hasYuan = true
            } else {
                hasFu = true
            }
        } else if c < '0' || c > '9' {
            return false
        }
    }
    return hasYuan && hasFu
}