/*
 * @Author: LetMeFly
 * @Date: 2024-05-30 17:16:55
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-05-30 17:31:45
 */
package main

func add(times []int, n int) {
    if n > times[2] {
        times[2] = n
        if times[2] > times[1] {
            times[2], times[1] = times[1], times[2]
            if times[1] > times[0] {
                times[1], times[0] = times[0], times[1]
            }
        }
    }
}

func max2(a int, b int) int {
    if a > b {
        return a
    }
    return b
}

func max3(a int, b int, c int) int {
    return max2(a, max2(b, c))
}

func min2(a int, b int) int {
    if a < b {
        return a
    }
    return b
}

func min3(a int, b int, c int) int {
    return min2(a, min2(b, c))
}

func getTimes(times []int) int {
    return max3 (
        min3(times[0], times[1], times[2]),
        min2(times[0] - 1, times[1]),
        times[0] - 2,  // 此逗号不可省略
    )
}

func maximumLength(s string) int {
    times := make([][3]int, 26)
    from := 0
    for i := 1; i <= len(s); i++ {
        if i == len(s) || s[i] != s[i - 1] {
            add(times[s[i - 1] - 'a'][:], i - from)
            from = i
        }
    }
    ans := 0
    for i := 0; i < 26; i++ {
        ans = max2(ans, getTimes(times[i][:]))
    }
    if ans != 0 {
        return ans
    }
    return -1
}