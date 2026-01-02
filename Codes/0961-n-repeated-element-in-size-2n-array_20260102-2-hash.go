/*
 * @Author: LetMeFly
 * @Date: 2026-01-02 17:26:31
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-02 17:27:52
 */
package main

func repeatedNTimes(nums []int) int {
    visited := map[int]bool{}
    for _, t := range nums {
        if _, ok := visited[t]; ok {
            return t
        }
        visited[t] = true
    }
    return -1  // FAKE RETURN
}