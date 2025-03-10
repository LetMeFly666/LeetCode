/*
 * @Author: LetMeFly
 * @Date: 2025-03-10 12:46:00
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-10 12:47:20
 */
package main

import "strconv"

func divisorSubstrings(num int, k int) (ans int) {
    s := strconv.Itoa(num)
    for i := 0; i < len(s) - k + 1; i++ {
        thisNum, _ := strconv.Atoi(s[i:i + k])
        if thisNum > 0 && num % thisNum == 0 {
            ans++
        }
    }
    return
}