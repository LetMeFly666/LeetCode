/*
 * @Author: LetMeFly
 * @Date: 2025-09-13 16:07:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-13 16:22:43
 */
package main

const mask int = 1<<0 | 1<<4 | 1<<8 | 1<<14 | 1<<20

func maxFreqSum(s string) int {
    times := make([]int, 26)
    for _, c := range s {
        times[byte(c) - 'a']++
    }
    cnt := []int{0, 0}
    for i, v := range times {
        idx := mask >> i & 1
        cnt[idx] = max(cnt[idx], v)
    }
    return cnt[0] + cnt[1]
}