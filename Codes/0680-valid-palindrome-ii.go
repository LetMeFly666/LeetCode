/*
 * @Author: LetMeFly
 * @Date: 2025-02-03 08:57:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-03 09:05:54
 */
package main

func isOk_VP(s string, l, r int) bool {
    for ; l < r; l, r = l + 1, r - 1 {
        if s[l] != s[r] {
            return false
        }
    }
    return true
}

func validPalindrome(s string) bool {
    for l, r := 0, len(s) - 1; l < r; l, r = l + 1, r - 1 {
        if s[l] != s[r] {
            return isOk_VP(s, l, r - 1) || isOk_VP(s, l + 1, r)
        }
    }
    return true
}