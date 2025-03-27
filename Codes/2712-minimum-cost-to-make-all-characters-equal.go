/*
 * @Author: LetMeFly
 * @Date: 2025-03-27 22:14:17
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-27 22:53:45
 * @Description: AC,100.00%,100.00%
 */
package main

func minimumCost(s string) (ans int64) {
    for i := 1; i < len(s); i++ {
        if s[i] != s[i - 1] {
            ans += int64(min(i, len(s) - i))
        }
    }
    return
}