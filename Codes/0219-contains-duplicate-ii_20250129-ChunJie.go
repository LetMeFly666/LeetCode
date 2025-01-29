/*
 * @Author: LetMeFly
 * @Date: 2025-01-29 11:56:06
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-29 11:57:59
 */
package main

func containsNearbyDuplicate(nums []int, k int) bool {
    ma := map[int]int{}
    for i, t := range nums {
        if p, ok := ma[t]; ok && i - p <= k {
            return true
        }
        ma[t] = i
    }
    return false
}