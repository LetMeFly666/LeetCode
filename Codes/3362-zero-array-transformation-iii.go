/*
 * @Author: LetMeFly
 * @Date: 2025-05-23 23:35:45
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-24 00:22:47
 */
package main

import (
    "slices"
    "container/heap"
)

func maxRemoval(nums []int, queries [][]int) int {
    slices.SortFunc(queries, func(a, b []int) int {
        return a[0] - b[0]
    })
    diff := make([]int, len(nums) + 1)
    pq := &pq3362{}
    for in, iq, cnt := 0, 0, 0; in < len(nums); in++ {
        cnt += diff[in]
        for iq < len(queries) && queries[iq][0] <= in {
            heap.Push(pq, queries[iq][1])
            iq++
        }
        for cnt < nums[in] && len(*pq) > 0 && (*pq)[0] >= in {
            cnt++
            diff[heap.Pop(pq).(int) + 1]--
        }
        if cnt < nums[in] {
            return -1
        }
    }
    return len(*pq)
}

type pq3362 []int
func (pq *pq3362) Push(a any)         {(*pq) = append((*pq), a.(int))}
func (pq pq3362)  Len() int           {return len(pq)}
func (pq pq3362)  Less(i, j int) bool {return pq[i] > pq[j]}
func (pq pq3362)  Swap(i, j int)      {pq[i], pq[j] = pq[j], pq[i]}
func (pq *pq3362) Pop() any           {a := (*pq)[len(*pq)-1]; (*pq) = (*pq)[:len(*pq)-1]; return a}