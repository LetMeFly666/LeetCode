/*
 * @Author: LetMeFly
 * @Date: 2025-02-06 13:57:39
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-06 14:22:26
 */
package main

import "sort"

func dfs_P2(n int, ans *[][]int, now []int, visited []bool, nums []int) {
    if n == len(nums) {
        *ans = append(*ans, append(make([]int, 0), now...))
        return
    }
    for i := range nums {
        if visited[i] || i > 0 && nums[i] == nums[i - 1] && !visited[i - 1] {
            continue
        }
        now = append(now, nums[i])
        visited[i] = true
        dfs_P2(n + 1, ans, now, visited, nums)
        visited[i] = false
        now = now[:len(now) - 1]
    }
}

func permuteUnique(nums []int) (ans [][]int) {
    sort.Ints(nums)
    var now []int
    visited := make([]bool, len(nums))
    dfs_P2(0, &ans, now, visited, nums)
    return ans;
}