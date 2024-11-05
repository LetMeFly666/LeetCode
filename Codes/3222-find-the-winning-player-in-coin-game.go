/*
 * @Author: LetMeFly
 * @Date: 2024-11-05 09:55:16
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-05 09:56:06
 */
package main

func losingPlayer(x int, y int) string {
    if min(x, y / 4) % 2 == 1 {
        return "Alice"
    }
    return "Bob"
}