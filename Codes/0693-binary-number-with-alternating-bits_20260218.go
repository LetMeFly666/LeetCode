/*
 * @Author: LetMeFly
 * @Date: 2026-02-18 14:51:23
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-18 15:01:13
 */
package main

func hasAlternatingBits(n int) bool {
    x := (n >> 1) ^ n
    return (x & (x + 1)) == 0
}