/*
 * @Author: LetMeFly
 * @Date: 2024-08-24 12:27:28
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-08-24 12:28:59
 */
package main

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}

func findPermutationDifference(s string, t string) int {
    ans := 0
    for i := 0; i < len(s); i++ {
        for j := 0; j < len(t); j++ {
            if s[i] == t[j] {
                ans += abs(i - j)
                break
            }
        }
    }
    return ans
}