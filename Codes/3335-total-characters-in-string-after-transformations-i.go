/*
 * @Author: LetMeFly
 * @Date: 2025-05-13 09:02:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-13 09:28:34
 */
package main

var MOD3351 = 1000000007

func lengthAfterTransformations(s string, t int) int {
    cnt := make([]int, 26)
    for i := 0; i < len(s); i++ {
        cnt[s[i] - 'a']++
    }
    ans := len(s)
    for i := 0; i < t; i++ {
        z := cnt[25]
        for j := 24; j >= 0; j-- {
            cnt[j + 1] = cnt[j]
        }
        cnt[0] = z
        cnt[1] = (cnt[1] + z) % MOD3351
        ans = (ans + z) % MOD3351
    }
    return ans
}