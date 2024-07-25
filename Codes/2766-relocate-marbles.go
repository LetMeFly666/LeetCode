/*
 * @Author: LetMeFly
 * @Date: 2024-07-25 12:50:03
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-25 12:54:36
 */
package main

import "sort"


func relocateMarbles(nums []int, moveFrom []int, moveTo []int) []int {
    se := map[int]struct{}{}
    for _, x := range nums {
        se[x] = struct{}{}
    }
    for i := 0; i < len(moveFrom); i++ {
        delete(se, moveFrom[i])
        se[moveTo[i]] = struct{}{}
    }
    ans := make([]int, 0, len(se))
    for x := range se {
        ans = append(ans, x)
    }
    sort.Ints(ans)
    return ans
}