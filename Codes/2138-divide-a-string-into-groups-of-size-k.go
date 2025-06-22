/*
 * @Author: LetMeFly
 * @Date: 2025-06-22 12:43:34
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-22 20:59:28
 */
package main

import "strings"

func divideString(s string, k int, fill byte) []string {
    ans := make([]string, 0, (len(s) + k - 1) / k)
    for i := 0; i < len(s); i += k {
        if len(s) - i < k {
            ans = append(ans, s[i:] + strings.Repeat(string(fill), k - (len(s) - i)))
        } else {
            ans = append(ans, s[i:i+k])
        }
    }
    return ans
}