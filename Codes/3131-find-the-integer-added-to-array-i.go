/*
 * @Author: LetMeFly
 * @Date: 2024-08-08 22:18:42
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-08-08 22:18:44
 */
package main

import "slices"

func addedInteger(nums1 []int, nums2 []int) int {
    return slices.Min(nums2) - slices.Min(nums1)
}