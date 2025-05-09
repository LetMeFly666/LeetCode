/*
 * @Author: LetMeFly
 * @Date: 2025-05-09 12:45:04
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-09 18:58:00
 */
package main

import "container/heap"

var directions3342 [][]int = [][]int{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}

func minTimeToReach(moveTime [][]int) int {
    n, m := len(moveTime), len(moveTime[0])
    ans := make([][]int, n)
    for i := range ans {
        ans[i] = make([]int, m)
        for j := range ans[i] {
            ans[i][j] = 2000000001
        }
    }
    ans[0][0] = 0
    pq := &pq3342{}
    heap.Init(pq)
    heap.Push(pq, node3342{0, 0, 0})
    for len(*pq) > 0 {
        node := heap.Pop(pq).(node3342)
        t, x, y := node.t, node.x, node.y
        if t > ans[x][y] {
            continue
        }
        for _, d := range directions3342 {
            nx := x + d[0]
            ny := y + d[1]
            if nx < 0 || nx >= n || ny < 0 || ny >= m {
                continue
            }
            nt := max(t, moveTime[nx][ny]) + (x + y) % 2 + 1
            if nt < ans[nx][ny] {
                ans[nx][ny] = nt
                heap.Push(pq, node3342{nt, nx, ny})
            }
        }
    }
    return ans[n - 1][m - 1]
}

type node3342 struct {
	t, x, y int
}

type pq3342 []node3342

func (pq pq3342) Len() int           {return len(pq)}
func (pq pq3342) Swap(i, j int)      {pq[i], pq[j] = pq[j], pq[i]} 
func (pq pq3342) Less(i, j int) bool {return pq[i].t < pq[j].t}
func (pq *pq3342) Pop() (ans any)    {*pq, ans = (*pq)[:len(*pq)-1], (*pq)[len(*pq)-1]; return}
func (pq *pq3342) Push(node any)     {*pq = append(*pq, node.(node3342))}