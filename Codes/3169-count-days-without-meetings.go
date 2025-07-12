/*
 * @Author: LetMeFly
 * @Date: 2025-07-11 23:25:31
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-12 17:00:47
 */
package main

import "slices"

func countDays(days int, meetings [][]int) (ans int) {
    last := 0
    slices.SortFunc(meetings, func(a, b []int) int {return a[0] - b[0]})
    for _, me := range meetings {
        if me[0] > last + 1 {
            ans += me[0] - last - 1
        }
        last = max(last, me[1])
    }
    ans += days - last
    return
}