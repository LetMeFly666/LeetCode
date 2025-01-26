/*
 * @Author: LetMeFly
 * @Date: 2025-01-26 08:47:10
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-26 09:01:49
 * @Descreption: AC,100.00%,34.12%
 */
package main

import "sort"

func dfs(c []int, target int, now []int, index int, ans *[][]int) {
    if target == 0 {
        *ans = append(*ans, append([]int{}, now...))
        return
    }
    if index == len(c) || target < 0 {
        return
    }
    now = append(now, c[index])
    dfs(c, target - c[index], now, index + 1, ans)
    now = now[:len(now) - 1]
    next := index + 1
    for next < len(c) && c[next] == c[index] {
        next++
    }
    dfs(c, target, now, next, ans)
}

func combinationSum2(candidates []int, target int) (ans [][]int) {
    var now []int
    sort.Ints(candidates)
    dfs(candidates, target, now, 0, &ans)
    return
}