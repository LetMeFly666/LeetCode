/*
 * @Author: LetMeFly
 * @Date: 2025-05-07 23:27:54
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-08 22:19:42
 */
package main
import "container/heap"

var directions [][]int = [][]int{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}

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
    pq := &pq3341{}
    heap.Init(pq)
    heap.Push(pq, node3341{0, 0, 0})
    for len(*pq) > 0 {
        node := heap.Pop(pq).(node3341)
        t, x, y := node.t, node.x, node.y
        if t > ans[x][y] {  // 注意不能是>=，因为入队时ans[x][y]会:=t
            continue
        }
        for _, d := range directions {
            nx := x + d[0]
            ny := y + d[1]
            if nx < 0 || nx >= n || ny < 0 || ny >= m {
                continue
            }
            nt := max(t, moveTime[nx][ny]) + 1
            if nt < ans[nx][ny] {
                ans[nx][ny] = nt
                heap.Push(pq, node3341{nt, nx, ny})
            }
        }
    }
    return ans[n - 1][m - 1]
}

type node3341 struct {
    t, x, y int
}

type pq3341 []node3341

func (pq *pq3341) Len() int           {return len(*pq)}
func (pq *pq3341) Less(i, j int) bool {return (*pq)[i].t < (*pq)[j].t}
func (pq *pq3341) Swap(i, j int)      {(*pq)[i], (*pq)[j] = (*pq)[j], (*pq)[i]}
func (pq *pq3341) Push(node any)      {*pq = append(*pq, node.(node3341))}
func (pq *pq3341) Pop() (ans any)     {*pq, ans = (*pq)[:len(*pq) - 1], (*pq)[len(*pq) - 1]; return ans}