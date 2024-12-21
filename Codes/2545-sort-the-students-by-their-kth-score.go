/*
 * @Author: LetMeFly
 * @Date: 2024-12-21 20:26:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-21 20:31:21
 */
package main

import "sort"

func sortTheStudents(score [][]int, k int) [][]int {
    sort.Slice(score, func(i, j int) bool {
        return score[i][k] > score[j][k]
    })
    return score
}