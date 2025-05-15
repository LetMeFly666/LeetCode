/*
 * @Author: LetMeFly
 * @Date: 2025-05-15 09:49:53
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-15 10:05:13
 */
package main

var MOD3337 = int64(1000000007)

type matrix3337 [26][26]int64

func pow(a matrix3337, b int) (ans matrix3337) {
    for i := 0; i < 26; i++ {
        ans[i][i] = 1
    }
    for ; b > 0; b >>= 1 {
        if b & 1 == 1 {
            ans = mul(ans, a)
        }
        a = mul(a, a)
    }
    return
}

func mul(a, b matrix3337) (ans matrix3337) {
    for i := 0; i < 26; i++ {
        for k := 0; k < 26; k++ {
            for j := 0; j < 26; j++ {
                ans[i][j] = (ans[i][j] + a[i][k] * b[k][j]) % MOD3337
            }
        }
    }
    return
}

func lengthAfterTransformations(s string, t int, nums []int) int {
    M := matrix3337{}
    for i, d := range nums {
        for j := 1; j <= d; j++ {
            M[i][(i + j) % 26] = 1
        }
    }
    Mt := pow(M, t)
    times := make([]int64, 26)
    for i := 0; i < len(s); i++ {
        times[s[i] - 'a']++
    }
    ans := int64(0)
    for i := 0; i < 26; i++ {
        sum := int64(0)
        for j := 0; j < 26; j++ {
            sum += Mt[i][j]
        }
        ans = (ans + sum * times[i]) % MOD3337
    }
    return int(ans)
}