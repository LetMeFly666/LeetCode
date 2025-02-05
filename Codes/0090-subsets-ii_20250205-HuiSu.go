/*
 * @Author: LetMeFly
 * @Date: 2025-02-05 12:29:25
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-05 12:42:51
 */
package main

import "sort"

var (
    ans [][]int
    now,
    a []int
)

func dfs_S2(loc int) {
    if loc == len(a) {
        ans = append(ans, append([]int{}, now...))
        return
    }
    // 选
    now = append(now, a[loc])
    dfs_S2(loc + 1)
    now = now[:len(now) - 1]
    // 不选
    next := loc + 1
    for next < len(a) && a[next] == a[loc] {
        next++
    }
    dfs_S2(next)
}

func subsetsWithDup(nums []int) [][]int {
    ans = make([][]int, 0)
    now = make([]int, 0)
    sort.Ints(nums)
    a = nums
    dfs_S2(0)
    return ans
}