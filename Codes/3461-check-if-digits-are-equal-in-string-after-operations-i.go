/*
 * @Author: LetMeFly
 * @Date: 2025-10-23 23:05:13
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-24 14:21:02
 */
package main

func hasSameDigits(s string) bool {
    a := make([]byte, len(s))
    for i := range s {
        a[i] = s[i] - '0'
    }
    for len(a) > 2 {
        b := make([]byte, len(a) - 1)
        for i := range b {
            b[i] = (a[i] + a[i + 1]) % 10
        }
        a = b
    }
    return a[0] == a[1]
}