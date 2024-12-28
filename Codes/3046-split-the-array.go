/*
 * @Author: LetMeFly
 * @Date: 2024-12-28 14:48:56
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-28 14:57:51
 */
package main

func isPossibleToSplit(nums []int) bool {
    times := map[int]int{}
    for _, n := range nums {
        times[n]++
        if (times[n] > 2) {
            return false
        }
    }
    return true
}