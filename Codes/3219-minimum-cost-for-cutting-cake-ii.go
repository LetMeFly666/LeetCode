/*
 * @Author: LetMeFly
 * @Date: 2024-12-31 13:23:11
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-31 13:37:03
 */
package main

import "slices"

func minimumCost(m int, n int, horizontalCut []int, verticalCut []int) (ans int64) {
    slices.SortFunc(horizontalCut, func(i, j int) int { return j - i; });
    slices.SortFunc(verticalCut, func(i, j int) int { return j - i; });
    var hCutTime, vCutTime int
    m, n = m - 1, n - 1
    for hCutTime < m || vCutTime < n {
        if vCutTime == n || hCutTime < m && horizontalCut[hCutTime] > verticalCut[vCutTime] {
            ans += int64(horizontalCut[hCutTime] * (vCutTime + 1))
            hCutTime++
        } else {
            ans += int64(verticalCut[vCutTime] * (hCutTime + 1))
            vCutTime++
        }
    }
    return
}