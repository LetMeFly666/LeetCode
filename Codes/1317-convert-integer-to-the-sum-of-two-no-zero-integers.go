/*
 * @Author: LetMeFly
 * @Date: 2025-09-08 23:05:58
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-08 23:16:59
 */
package main

func nonZero1317(n int) bool {
    for n > 0 {
        if n % 10 == 0 {
            return false
        }
        n /= 10
    }
    return true
}

func getNoZeroIntegers(n int) (ans []int) {
    for i := 1; i < n; i++ {
        if nonZero1317(i) && nonZero1317(n - i) {
            return []int{i, n - i}
        }
    }
    return
}