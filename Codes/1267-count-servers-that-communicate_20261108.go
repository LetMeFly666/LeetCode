/*
 * @Author: LetMeFly
 * @Date: 2026-11-08 10:46:44
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-11-08 10:52:49
 */
package main

func countServers(grid [][]int) (ans int) {
	n, m := len(grid), len(grid[0])
	a, b := make([]int, n), make([]int, m)
	for i, row := range grid {
		for j, v := range row {
			if v == 1 {
				a[i]++
				b[j]++
			}
		}
	}

	for i, row := range grid {
		for j, v := range row {
			if v == 1 && (a[i] > 1 || b[j] > 1) {
				ans++
			}
		}
	}
	return
}
