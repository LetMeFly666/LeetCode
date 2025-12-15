/*
 * @Author: LetMeFly
 * @Date: 2025-12-15 13:32:17
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-15 21:35:08
 */
package main

// THIS CANNOT ACCESS
func getDescentPeriods(prices []int) (ans int64) {
    var cnt int64
    last := 0
    for i := 0; i <= len(prices); i++ {
        if i == len(prices) || prices[i] != last - 1 {
            ans += cnt * (cnt + 1) / 2
            cnt = 0
        }
        cnt++
        if i < len(prices) {
            last = prices[i]
        }
    }
    return
}