package main

import "sort"

func removeCoveredIntervals(intervals [][]int) int {
	sort.Slice(intervals, func(i, j int) bool {
		if intervals[i][0] == intervals[j][0] {
			return intervals[i][1] > intervals[j][1]
		}
		return intervals[i][0] < intervals[j][0]
	})
	ans, maxr := len(intervals), 0
	for _, p := range intervals {
		if p[1] <= maxr {
			ans--
		} else {
			maxr = p[1]
		}
	}
	return ans
}
