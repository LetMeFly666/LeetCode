/*
 * @Author: LetMeFly
 * @Date: 2025-01-30 08:26:09
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-30 08:27:29
 */
package main

func intersect(nums1 []int, nums2 []int) (ans []int) {
    ma := map[int]int{}
    for _, t := range nums1 {
        ma[t]++
    }
    for _, t := range nums2 {
        if ma[t] > 0 {
            ans = append(ans, t)
            ma[t]--
        }
    }
    return
}