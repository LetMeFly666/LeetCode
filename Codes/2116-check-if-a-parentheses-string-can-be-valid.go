/*
 * @Author: LetMeFly
 * @Date: 2025-03-23 10:54:53
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-23 10:56:04
 */
package main

func canBeValid(s string, locked string) bool {
    l, r := 0, 0
    for i := range s {
        if locked[i] == '0' {
            l--
            r++
            if l < 0 {
                l = 1
            }
        } else {
            if s[i] == '(' {
                l++
                r++
            } else {
                l--
                r--
                if r < 0 {
                    return false
                }
                if l < 0 {
                    l = 1
                }
            }
        }
    }
    return l == 0
}