/*
 * @Author: LetMeFly
 * @Date: 2025-02-13 16:22:21
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-13 16:31:13
 */
package main

func get_MNB1B(n int) (ans int) {
    for n > 0 {
        ans += n % 10
        n /= 10
    }
    return
}

func min_MNB1B(a, b int) int {
    if a < b {
        return a
    }
    return b
}

func countBalls(l int, h int) (ans int) {
    cnt := make([]int, 46)
    for ; l <= h; l++ {
        thisCnt := get_MNB1B(l)
        cnt[thisCnt]++
        ans = max(ans, cnt[thisCnt])
    }
    return
}