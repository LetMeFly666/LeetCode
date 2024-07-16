/*
 * @Author: LetMeFly
 * @Date: 2024-07-16 23:32:36
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-16 23:35:53
 */
package main

func findIntersectionValues(nums1 []int, nums2 []int) []int {
    s1, s2 := map[int]int{}, map[int]int{}
    for _, t := range nums1 {
        s1[t] = 1
    }
    for _, t := range nums2 {
        s2[t] = 1
    }
    ans := [2]int{}
    for _, t := range nums1 {
        ans[0] += s2[t]
    }
    for _, t := range nums2 {
        ans[1] += s1[t]
    }
    return ans[:]
}