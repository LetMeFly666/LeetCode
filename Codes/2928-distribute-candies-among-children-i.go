/*
 * @Author: LetMeFly
 * @Date: 2024-06-01 11:48:10
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-01 11:49:32
 */
package main

func distributeCandies(n int, limit int) int {
    ans := 0
    for x := 0; x <= n && x <= limit; x++ {
        for y := 0; y <= n - x && y <= limit; y++ {
            if n - x - y <= limit {
                ans++
            }
        }
    }
    return ans
}