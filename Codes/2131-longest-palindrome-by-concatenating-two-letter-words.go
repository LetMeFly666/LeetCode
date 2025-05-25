/*
 * @Author: LetMeFly
 * @Date: 2025-05-25 23:39:17
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-25 23:54:22
 */
package main

func longestPalindrome(words []string) int {
    times := make([][]int, 26)
    for i := range times {
        times[i] = make([]int, 26)
    }
    for _, word := range words {
        times[word[0] - 'a'][word[1] - 'a']++
    }
    side, mid := 0, 0
    for i := range times {
        side += times[i][i] / 2 * 2
        mid |= times[i][i] % 2
        for j := i + 1; j < 26; j++ {
            side += min(times[i][j], times[j][i]) * 2
        }
    }
    return (side + mid) * 2
}