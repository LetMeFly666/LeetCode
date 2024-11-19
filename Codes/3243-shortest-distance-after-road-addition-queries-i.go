/*
 * @Author: LetMeFly
 * @Date: 2024-11-19 15:00:03
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-19 15:04:56
 */
package main

func shortestDistanceAfterQueries(n int, queries [][]int) (ans []int) {
    shortest := make([]int, n)
    fromList := make([][]int, n)
    for i := range shortest {
        shortest[i] = i
        fromList[i] = make([]int, 0)
        fromList[i] = append(fromList[i], i - 1)
    }
    ans = make([]int, len(queries))
    for i, query := range queries {
        fromList[query[1]] = append(fromList[query[1]], query[0])
        for j := query[1]; j < n; j++ {
            for _, from := range fromList[j] {
                shortest[j] = min(shortest[j], shortest[from] + 1)
            }
        }
        ans[i] = shortest[n - 1]
    }
    return
}