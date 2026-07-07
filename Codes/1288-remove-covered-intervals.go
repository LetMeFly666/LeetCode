/*
 * @Author: LetMeFly
 * @Date: 2026-07-07 22:09:22
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-07 22:24:39
 */
package main

import "sort"

func removeCoveredIntervals(intervals [][]int) int {
	sort.Slice(intervals, func(i, j int) bool {
		if intervals[i][0] == intervals[i][1] {
			return intervals[1][1] > intervals[j][1]
		}
		return intervals[i][0] < intervals[j][0]
	})
	
	ans := len(intervals)
	r := 0
	for _, v := range intervals {
		if v[1] <= r {
			ans -= 1
		}
		r = max(r, v[1])
	}
	return ans
}
