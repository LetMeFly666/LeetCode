/*
 * @Author: LetMeFly
 * @Date: 2025-05-10 12:07:54
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-10 19:38:55
 */
package main

func cal2918(a []int) (s int64, cnt int64) {
    for _, t := range a {
        if (t == 0) {
            cnt++
        } else {
            s += int64(t)
        }
    }
    return
}

func minSum(nums1 []int, nums2 []int) int64 {
    s1, c1 := cal2918(nums1)
    s2, c2 := cal2918(nums2)
    if s1 < s2 + c2 && c1 == 0 || s1 + c1 > s2 && c2 == 0 {
        return -1
    }
    return max(s1 + c1, s2 + c2)
}