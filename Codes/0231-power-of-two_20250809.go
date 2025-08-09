/*
 * @Author: LetMeFly
 * @Date: 2025-08-09 22:23:22
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-09 22:37:37
 */
package main

func isPowerOfTwo(n int) bool {
    return n > 0 && n & (n - 1) == 0
}