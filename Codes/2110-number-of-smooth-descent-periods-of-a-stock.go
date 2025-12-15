/*
 * @Author: LetMeFly
 * @Date: 2025-12-15 13:32:17
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-15 18:58:05
 */
package main

// THIS CANNOT ACCESS
func getDescentPeriods(prices []int) (ans int64) {
    var cnt int64
    last := 0
    for i, p := range prices {
        if i == len(prices) - 1 || p != last - 1 {
            ans += cnt * (cnt + 1) / 2
            cnt = 0
        }
        cnt++
        last = p
    }
    return
}