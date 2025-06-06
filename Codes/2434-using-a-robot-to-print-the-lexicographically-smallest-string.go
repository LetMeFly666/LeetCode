/*
 * @Author: LetMeFly
 * @Date: 2025-06-06 21:49:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-06 23:06:01
 */
package main

func robotWithString(s string) string {
    mini := make([]byte, len(s) + 1)
    mini[len(s)] = 'z'
    for i := len(s) - 1; i >= 0; i-- {
        mini[i] = min(mini[i + 1], s[i])
    }
    st := mini[:0]
    ans := make([]byte, 0, len(s))
    for i := 0; i < len(s); i++ {
        st = append(st, s[i])
        for len(st) > 0 && st[len(st) - 1] <= mini[i + 1] {
            ans = append(ans, st[len(st) - 1])
            st = st[:len(st) - 1]
        }
    }
    return string(ans)
}