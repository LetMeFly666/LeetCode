/*
 * @Author: LetMeFly
 * @Date: 2025-09-15 21:48:47
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-15 22:06:31
 */
package main

func canBeTypedWords(text string, brokenLetters string) (ans int) {
    cannot := map[byte]struct{}{}
    for i := range brokenLetters {
        cannot[brokenLetters[i]] = struct{}{}
    }
    can := true
    for i := range text {
        if text[i] == ' ' {
            if can {
                ans++
            } else {
                can = true
            }
            continue
        }
        if _, in := cannot[text[i]]; in {
            can = false
        }
    }
    if can {
        ans++
    }
    return
}