/*
 * @Author: LetMeFly
 * @Date: 2025-01-31 12:17:35
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-31 12:18:54
 */
package main

import "slices"

func reverseStr(s1 string, k int) string {
    s := []byte(s1)
    for i := 0; i < len(s); i += k * 2 {
        slices.Reverse(s[i:min(i + k, len(s))])
    }
    return string(s)
}