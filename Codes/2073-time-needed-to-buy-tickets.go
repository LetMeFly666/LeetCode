/*
 * @Author: LetMeFly
 * @Date: 2024-10-03 13:51:42
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-03 13:56:47
 */
package main

func timeRequiredToBuy(tickets []int, k int) int {
    ans := 0
    for th, t := range tickets {
        if th <= k {
            ans += min(t, tickets[k])
        } else {
            ans += min(t, tickets[k] - 1)
        }
    }
    return ans
}