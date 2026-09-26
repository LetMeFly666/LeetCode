/*
 * @Author: LetMeFly
 * @Date: 2026-01-26 23:38:09
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-26 23:48:45
 */
package main

import "sort"

func minimumAbsDifference(arr []int) (ans [][]int) {
    sort.Ints(arr)
	mini := 10000000
	for i := 1; i < len(arr); i++ {
		diff := arr[i] - arr[i - 1]
		if diff < mini {
			mini = diff
			ans = [][]int{{arr[i - 1], arr[i]}}
		} else if diff == mini {
			ans = append(ans, []int{arr[i - 1], arr[i]})
		}
	}
	return
}