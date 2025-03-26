/*
 * @Author: LetMeFly
 * @Date: 2025-03-26 13:50:19
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-26 13:50:45
 */
package main

func minimumSum(n int, k int) int {
    to := min(n, k / 2)
    n -= to
    return to * (to + 1) / 2 + n * (k + k + n - 1) / 2
}