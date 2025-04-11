/*
 * @Author: LetMeFly
 * @Date: 2025-04-11 21:19:27
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-11 21:26:25
 */
package main

import (
    // "fmt"
    "strconv"
)

func isOK2843(n int) int {
    s := strconv.Itoa(n)
    if len(s) % 2 == 1 {
        return 0
    }
    cnt := 0
    for i := 0; i < len(s) / 2; i++ {
        cnt += int(s[i]) - int(s[len(s) - i - 1])  // 不能int(s[i] - s[len(s) - i - 1])
    }
    if cnt == 0 {
        return 1
    }
    return 0
}

func countSymmetricIntegers(low int, high int) (ans int) {
    for i := low; i <= high; i++ {
        // fmt.Println(i, isOK2843(i))
        ans += isOK2843(i)
    }
    return
}