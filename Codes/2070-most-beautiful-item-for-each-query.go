/*
 * @Author: LetMeFly
 * @Date: 2025-03-09 14:12:40
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-09 14:17:20
 */
package main

import "sort"

func search_2070(items [][]int, target int) int {
    l, r := 0, len(items) - 1
    for l <= r {
        mid := (l + r) >> 1
        if items[mid][0] > target {
            r = mid - 1
        } else {
            l = mid + 1
        }
    }
    return l
}

func maximumBeauty(items [][]int, queries []int) []int {
    sort.Slice(items, func(i, j int) bool {
        return items[i][0] < items[j][0]
    })
    cnt := 0
    for _, item := range items {
        cnt = max(cnt, item[1])
        item[1] = cnt
    }
    for i, q := range queries {
        index := search_2070(items, q)
        if index > 0 {
            queries[i] = items[index - 1][1]
        } else {
            queries[i] = 0
        }
    }
    return queries
}