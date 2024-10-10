/*
 * @Author: LetMeFly
 * @Date: 2024-10-10 13:00:09
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-10 13:00:23
 */
package main

func numberOfPairs(nums1 []int, nums2 []int, k int) int {
    ans := 0
    for _, n1 := range nums1 {
        for _, n2 := range nums2 {
            if n1 % (n2 * k) == 0 {
                ans++
            }
        }
    }
    return ans
}