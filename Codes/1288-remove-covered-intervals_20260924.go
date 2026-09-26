/*
 * @Author: LetMeFly
 * @Date: 2026-09-24 12:11:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-24 12:36:53
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
	maxr := -1
	for _, v := range intervals {
		if maxr >= v[1] {
			ans--
		} else {
			maxr = v[1]
		}
	}
	return ans
}
