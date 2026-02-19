/*
 * @Author: LetMeFly
 * @Date: 2026-02-19 17:59:08
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-19 18:02:40
 */
package main

func countOdds(low int, high int) int {
    if low % 2 == 1 {
        low--
    }
    if high % 2 == 1 {
        high++
    }
    return (high - low) / 2
}