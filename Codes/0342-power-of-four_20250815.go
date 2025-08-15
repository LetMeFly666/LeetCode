/*
 * @Author: LetMeFly
 * @Date: 2025-08-15 18:29:00
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-15 23:54:26
 */
package main

func isPowerOfFour(n int) bool {
    return n > 0 && n & (n - 1) == 0 && n % 3 == 1
}