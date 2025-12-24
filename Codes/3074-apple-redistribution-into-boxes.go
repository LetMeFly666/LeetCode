/*
 * @Author: LetMeFly
 * @Date: 2025-12-24 13:30:54
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-24 13:45:02
 */
package main

import "sort"

func minimumBoxes(apple []int, capacity []int) int {
    cnt := 0
    for _, t := range apple {
        cnt += t
    }
    sort.Sort(sort.Reverse(sort.IntSlice(capacity)))
    for i, t := range capacity {
        cnt -= t
        if cnt <= 0 {
            return i + 1
        }
    }
    return -1  // Fake Return
}