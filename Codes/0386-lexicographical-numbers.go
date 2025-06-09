/*
 * @Author: LetMeFly
 * @Date: 2025-06-09 10:09:21
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-09 22:03:40
 */
package main

func lexicalOrder(n int) []int {
    ans := make([]int, n)
    for now, i := 1, 0; i < n; i++ {
        ans[i] = now
        if now * 10 <= n {
            now *= 10
        } else {
            for now % 10 == 9 || now == n {
                now /= 10
            }
            now++
        }
    }
    return ans
}