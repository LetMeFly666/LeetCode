/*
 * @Author: LetMeFly
 * @Date: 2024-10-03 13:04:05
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-03 13:12:26
 */
package main

func min(a int, b int) int {
    if a <= b {
        return a
    }
    return b
}

func minCost(maxTime int, edges [][]int, passingFees []int) int {
    dp := make([][]int, maxTime + 1)
    // for _, d := range dp {
    //     d = make([]int, len(passingFees))
    //     for i := range d {
    //         d[i] = 10000000
    //     }
    // }
    for th := range dp {
        dp[th] = make([]int, len(passingFees))
        for i := range dp[th] {
            dp[th][i] = 10000000
        }
    }
    dp[0][0] = passingFees[0]
    
    for t := 1; t <= maxTime; t++ {
        for _, edge := range edges {
            i, j, cost := edge[0], edge[1], edge[2]
            if cost <= t {
                dp[t][j] = min(dp[t][j], dp[t - cost][i] + passingFees[j])
                dp[t][i] = min(dp[t][i], dp[t - cost][j] + passingFees[i])
            }
        }
    }

    ans := 10000000
    for _, d := range dp {
        ans = min(ans, d[len(passingFees) - 1])
    }
    if ans == 10000000 {
        return -1
    }
    return ans
}