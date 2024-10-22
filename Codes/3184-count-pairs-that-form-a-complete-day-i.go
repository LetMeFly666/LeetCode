/*
 * @Author: LetMeFly
 * @Date: 2024-10-22 18:32:37
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-22 19:03:21
 */
package main

func countCompleteDayPairs(hours []int) int {
    ans := 0
    for i, h1 := range hours {
        for j := i + 1; j < len(hours); j++ {
            if (h1 + hours[j]) % 24 == 0 {
                ans++
            }
        }
    }
    return ans
}