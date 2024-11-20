/*
 * @Author: LetMeFly
 * @Date: 2024-11-20 13:03:17
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-20 13:06:36
 */
package main

func shortestDistanceAfterQueries(n int, queries [][]int) (ans []int) {
    transitionTo := make([]int, n)
    for i := range transitionTo {
        transitionTo[i] = i + 1
    }
    minTimes := n - 1
    for _, query := range queries {
        from, to := query[0], query[1]
        for transitionTo[from] < to {
            minTimes--
            transitionTo[from], from = to, transitionTo[from]
        }
        ans = append(ans, minTimes)
    }
    return
}  // AC,81.82%,29.41%