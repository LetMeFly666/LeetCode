/*
 * @Author: LetMeFly
 * @Date: 2025-07-21 18:48:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-21 18:57:03
 */
package main

func makeFancyString(s string) string {
    ans := []byte{}
    last := byte(0)
    cnt := 0
    for _, c := range s {
        if byte(c) != last {
            last = byte(c)
            cnt = 0
        }
        cnt++
        if cnt < 3 {
            ans = append(ans, byte(c))
        }
    }
    return string(ans)
}