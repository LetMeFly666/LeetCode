/*
 * @Author: LetMeFly
 * @Date: 2025-12-25 12:56:03
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-25 13:08:10
 */
package main

import "sort"

func maximumHappinessSum(happiness []int, k int) (ans int64) {
    sort.Slice(happiness, func(i, j int) bool { return happiness[i] > happiness[j] })
    for i := 0; i < k; i++ {
        happiness[i] -= i
        if happiness[i] <= 0 {
            return
        }
        ans += int64(happiness[i])
    }
    return
}