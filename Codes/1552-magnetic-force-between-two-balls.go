/*
 * @Author: LetMeFly
 * @Date: 2025-02-14 10:56:28
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-14 11:05:50
 */
package main

import "slices"

func check_MFB2B(v []int, m, d int) bool {
    last := -1000000000
    for _, t := range v {
        if t - last >= d {
            m--
            if m <= 0 {
                return true
            }
            last = t
        }
    }
    return false
}

func maxDistance(position []int, m int) int {
    slices.Sort(position)
    l, r := 1, position[len(position) - 1] - position[0]
    for l < r {
        mid := (l + r + 1) >> 1
        if check_MFB2B(position, m, mid) {
            l = mid
        } else {
            r = mid - 1
        }
    }
    return l
}