/*
 * @Author: LetMeFly
 * @Date: 2026-07-11 07:59:33
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-11 08:04:27
 */
package main

import "sort"

func removeCoveredIntervals(intervals [][]int) int {
	sort.Slice(intervals, func(i, j int) bool {
		if intervals[i][0] == intervals[j][0] {
			return intervals[i][1] > intervals[j][1]
		}
		return intervals[i][0] < intervals[j][0]
	})

	ans := len(intervals)
	maxr := 0
	for _, v := range intervals {
		if v[1] <= maxr {
			ans--
		} else {
			maxr = v[1]
		}
	}
	return ans
}
