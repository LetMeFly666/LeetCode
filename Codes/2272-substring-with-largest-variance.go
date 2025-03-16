/*
 * @Author: LetMeFly
 * @Date: 2025-03-16 11:14:38
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-16 11:18:01
 */
package main

func largestVariance(s string) (ans int) {
    for i := byte(0); i < 26; i++ {
        a := i + 'a'
        for j := byte(0); j < 26; j++ {
            b := j + 'a'
            mayNoB, hasB := 0, -10000000
            for _, c := range s {
                if byte(c) == a {
                    mayNoB = max(mayNoB + 1, 1)
                    hasB++
                } else if byte(c) == b {
                    mayNoB = max(mayNoB - 1, -1)
                    hasB = mayNoB
                }
                ans = max(ans, hasB)
            }
        }
    }
    return
}