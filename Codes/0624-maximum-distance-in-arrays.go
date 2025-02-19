/*
 * @Author: LetMeFly
 * @Date: 2025-02-19 17:47:56
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-19 17:53:37
 */
package main

func maxDistance(arrays [][]int) (ans int) {
    m, M := 100000, -100000
    for _, a := range arrays {
        ans = max(ans, max(a[len(a) - 1] - m, M - a[0]))
        m, M = min(m, a[0]), max(M, a[len(a) - 1])
    }
    return
}