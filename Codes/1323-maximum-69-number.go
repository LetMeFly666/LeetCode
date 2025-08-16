/*
 * @Author: LetMeFly
 * @Date: 2025-08-16 10:17:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-16 10:43:00
 */
package main

import (
    "strconv"
    "strings"
)

func maximum69Number (num int) (ans int) {
    s := strconv.Itoa(num)
    s = strings.Replace(s, "6", "9", 1)
    ans, _ = strconv.Atoi(s)
    return
}