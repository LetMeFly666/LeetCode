/*
 * @Author: LetMeFly
 * @Date: 2026-09-15 17:12:02
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-15 17:21:29
 */
package main

import "slices"

func removeCoveredIntervals(intervals [][]int) int {
	slices.sort(intervals, func(i, j int) bool {
		if intervals[i][0] == intervals[j][0] {
			return intervals[i][1] > intervals[j][1]
		}
		return intervals[i][0] < intervals[j][0]
	})
	
	ans := len(intervals)
	maxr := -1
	for _, p := range intervals {
		if p[1] <= maxr {
			ans--
		} else {
			maxr = p[1]
		}
	}
	return ans
}
