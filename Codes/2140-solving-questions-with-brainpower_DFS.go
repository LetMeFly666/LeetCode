/*
 * @Author: LetMeFly
 * @Date: 2025-04-03 23:39:08
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-03 23:46:51
 */
package main

var q [][]int
// var cache = make(map[int]int64)  // 不可！会被力扣多次调用
var cache map[int]int64  // 这里声明即可，每次在mostPoints时重新赋值

func dfs2140(i int) int64 {
    if i >= len(q) {
        return 0
    }
    if val, ok := cache[i]; ok {
        return val
    }
    ans := max(dfs2140(i + 1), dfs2140(i + q[i][1] + 1) + int64(q[i][0]))
    cache[i] = ans
    return ans
}

func mostPoints(questions [][]int) int64 {
    q = questions
    cache = make(map[int]int64)
    return dfs2140(0)
}