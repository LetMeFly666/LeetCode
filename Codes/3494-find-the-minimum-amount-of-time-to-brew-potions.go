/*
 * @Author: LetMeFly
 * @Date: 2025-10-09 22:52:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-09 23:32:19
 */
package main

func minTime(skill []int, mana []int) int64 {
    n := len(skill)
    times := make([]int64, n)
    for _, m := range mana {
        lastTime := times[0] + int64(skill[0] * m)
        for i := 1; i < n; i++ {
            lastTime = max3494(times[i], lastTime) + int64(skill[i] * m)
        }
        times[n-1] = lastTime
        for i := n - 2; i >= 0; i-- {
            times[i] = times[i + 1] - int64(skill[i + 1] * m)
        }
    }
    return times[n-1]
}

func max3494(a, b int64) int64 {
    if a > b {
        return a
    }
    return b
}