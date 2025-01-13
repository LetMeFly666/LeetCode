/*
 * @Author: LetMeFly
 * @Date: 2025-01-13 23:49:56
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-13 23:52:27
 */
package main


func min_FKN(a, b, c int) int {
    if a > b {
        a = b
    }
    if a > c {
        a = c
    }
    return a
}

func generateKey(num1 int, num2 int, num3 int) (ans int) {
    p := 1
    for num1 + num2 + num3 > 0 {
        ans += min_FKN(num1 % 10, num2 % 10, num3 % 10) * p
        p *= 10
        num1, num2, num3 = num1 / 10, num2 / 10, num3 / 10
    }
    return
}