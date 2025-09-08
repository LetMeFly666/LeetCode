/*
 * @Author: LetMeFly
 * @Date: 2025-09-08 23:05:58
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-08 23:15:34
 */
package main

func nonZero1317(n int) bool {
    for n > 0 {
        if n % 10 == 0 {
            return false
        }
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