/*
 * @Author: LetMeFly
 * @Date: 2024-05-26 09:39:35
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-05-26 09:54:38
 */
package main

import "sort"

func kthLargestValue(matrix [][]int, k int) int {
    prefix := make([][]int, len(matrix) + 1)
    prefix[0] = make([]int, len(matrix[0]) + 1)
    vals := make([]int, 0)
    for i := 0; i < len(matrix); i++ {
        prefix[i + 1] = make([]int, len(matrix[0]) + 1)
        for j := 0; j < len(matrix[0]); j++ {
            prefix[i + 1][j + 1] = prefix[i + 1][j] ^ prefix[i][j + 1] ^ prefix[i][j] ^ matrix[i][j]
            vals = append(vals, prefix[i + 1][j + 1])
        }
    }
    sort.Ints(vals)
    return vals[len(vals) - k]
}