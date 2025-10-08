/*
 * @Author: LetMeFly
 * @Date: 2025-10-06 12:17:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-06 14:31:37
 */
package main

import "container/heap"

type Item778 struct {
    x, y int
    val int
}

type PriorityQueue778 []*Item778

var directions778 = [][]int{{0, 1}, {0, -1}, {-1, 0}, {1, 0}}

func swimInWater(grid [][]int) int {
    n, m := len(grid), len(grid[0])
    if n == 1 && m == 1 {
        return grid[0][0]
    }
    visited := make([][]bool, n)
    for i, _ := range visited {
        visited[i] = make([]bool, m)
    }

    pq := &PriorityQueue778{}
    heap.Init(pq)
    heap.Push(pq, &Item778{0, 0, grid[0][0]})
    visited[0][0] = true
    for true {
        item := heap.Pop(pq).(*Item778)
        x, y, val := item.x, item.y, item.val
        for _, d := range directions778 {
            nx, ny := x + d[0], y + d[1]
            if nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] {
                continue
            }
            grid[nx][ny] = max(grid[nx][ny], val)
            if nx == n - 1 && ny == m - 1 {
                return grid[nx][ny]
            }
            visited[nx][ny] = true
            heap.Push(pq, &Item778{nx, ny, grid[nx][ny]})
        }
    }

    return -1  // Fake Return
}

func (pq PriorityQueue778) Len() int { return len(pq) }
func (pq PriorityQueue778) Less(i, j int) bool { return pq[i].val < pq[j].val }
func (pq PriorityQueue778) Swap(i, j int) { pq[i], pq[j] = pq[j], pq[i] }
func (pq *PriorityQueue778) Push(x any) { *pq = append(*pq, x.(*Item778)) }
func (pq *PriorityQueue778) Pop() any { n := len(*pq); item := (*pq)[n - 1]; *pq = (*pq)[:n-1]; return item }
