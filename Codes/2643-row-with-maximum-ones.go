/*
 * @Author: LetMeFly
 * @Date: 2025-03-22 22:51:01
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-22 22:52:04
 */
package main

func rowAndMaximumOnes(mat [][]int) []int {
    ans, mx := 0, 0
    for i := range mat {
        cnt := 0
        for _, t := range mat[i] {
            cnt += t
        }
        if cnt > mx {
            ans, mx = i, cnt
        }
    }
    return []int{ans, mx}
}