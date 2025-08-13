/*
 * @Author: LetMeFly
 * @Date: 2025-08-13 13:17:09
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-13 13:23:55
 */
package main

func isPowerOfThree(n int) bool {
    return n > 0 && 1162261467 % n == 0
}