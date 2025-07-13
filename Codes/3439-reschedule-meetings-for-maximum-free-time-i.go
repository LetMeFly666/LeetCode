/*
 * @Author: LetMeFly
 * @Date: 2025-07-13 21:44:10
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-13 22:19:42
 */
package main

func maxFreeTime(eventTime int, k int, startTime []int, endTime []int) (ans int) {
    cnt := 0
    for i := 0; i <= k; i++ {
        cnt += endTime[i] - startTime[i]
    }
    n := len(startTime)
    for i := k; i <= n; i++ {
        var l, r int
        if i == k {
            l = cnt
        } else {
            l = endTime[i - k - 1] + cnt
        }
        if i == n {
            r = eventTime
        } else {
            r = startTime[i]
        }
        ans = max(ans, r - l)
        if i == n {
            break
        }
        cnt += endTime[i] - startTime[i]
        cnt -= endTime[i - k] - startTime[i - k]
    }
    return ans
}