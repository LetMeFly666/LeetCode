/*
 * @Author: LetMeFly
 * @Date: 2025-06-26 22:16:30
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-26 22:39:55
 */
package main

import "math/bits"

func longestSubsequence(s string, k int) (ans int) {
    val, n, lenK := 0, len(s), bits.Len(uint(k))
    for i := 0; i < n; i++ {
        if s[n - i - 1] == '0' {
            ans++
            continue
        }
        if i < lenK && val + (1 << i) <= k {
            ans++
            val += 1 << i
        }
    }
    return
}