/*
 * @Author: LetMeFly
 * @Date: 2024-12-16 22:22:33
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-17 09:03:54
 */
package main

import "sort"

func closestRoom(rooms [][]int, queries [][]int) []int {
    queryIdx := make([]int, len(queries))
    for i := range queryIdx {
        queryIdx[i] = i
    }
    sort.Slice(queryIdx, func(i, j int) bool {
        return queries[i][1] > queries[j][1]
    })
    sort.Slice(rooms, func(i, j int) bool {
        return rooms[i][1] > rooms[j][1]
    })
    // HALF: 有序集合似乎要么手动实现一些功能更，要么(→)之类的： import "github.com/emirpasic/gods/v2/trees/redblacktree"
}