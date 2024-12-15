/*
 * @Author: LetMeFly
 * @Date: 2024-12-15 15:15:11
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-15 15:28:42
 */
package main
import "sort"

func minSetSize(arr []int) (ans int) {
    ma := map[int]int{}
    for _, t := range arr {
        ma[t]++
    }
    var times []int
    for _, t := range ma {
        times = append(times, t)
    }
    sort.Slice(times, func(i, j int) bool {
        return times[i] > times[j]
    })
    for cnt := 0; cnt < len(arr) / 2; ans++ {
        cnt += times[ans]
    }
    return
}