/*
 * @Author: LetMeFly
 * @Date: 2025-04-23 13:26:23
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-23 13:28:41
 */
package main

func countLargestGroup(n int) (ans int) {
    times := map[int]int{}
    maxTimes := 0
    for i := 1; i <= n; i++ {
        cnt := 0
        for temp := i; temp > 0; temp /= 10 {
            cnt += temp % 10
        }
        times[cnt]++
        maxTimes = max(maxTimes, times[cnt])
    }
    for _, val := range times {
        if val == maxTimes {
            ans++
        }
    }
    return
}