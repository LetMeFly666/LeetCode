/*
 * @Author: LetMeFly
 * @Date: 2026-10-25 09:03:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-25 12:16:55
 */
package main

func isCenter1254(i, j, n, m int) bool {
	return 0 < i && i < n - 1 && 0 < j && j < m - 1
}

func inGrid1254(i, j, n, m int) bool {
	return 0 <= i && i < n && 0 <= j && j < m
}

var dirs1254 = [4][2]int{{0, -1}, {0, 1}, {1, 0}, {-1, 0}}

func closedIsland(grid [][]int) (ans int) {
	n, m := len(grid), len(grid[0])
	for i, line := range grid {
		for j, v := range line {
			if v == 1 {
				continue
			}
			ok := isCenter1254(i, j, n, m)
			grid[i][j] = 1
			q := [][2]int{{i, j}}
			for len(q) > 0 {
				top := q[len(q) - 1]
				q = q[:len(q) - 1]
				x, y := top[0], top[1]
				for _, d := range dirs1254 {
					nx, ny := x + d[0], y + d[1]
					if !inGrid1254(nx, ny, n, m) || grid[nx][ny] == 1 {
						continue
					}
					grid[nx][ny] = 1
					ok = ok && isCenter1254(nx, ny, n, m)  // go没有bool的&
					q = append(q, [2]int{nx, ny})
				}
			}
			if ok {
				ans++
			}
		}
	}
	return
}
