/*
 * @Author: LetMeFly
 * @Date: 2025-01-15 14:37:30
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-15 14:53:17
 */
package main

import "container/heap"

func minOperations(nums []int, k int) (ans int) {
    pq := make(heap_MOETV2, 0)
    heap.Init(&pq)
    for _, n := range nums {
        heap.Push(&pq, n)
    }
    for ; pq[0] < k; ans++ {
        x, y := heap.Pop(&pq).(int), heap.Pop(&pq).(int)
        heap.Push(&pq, x + x + y)
    }
    return
}


type heap_MOETV2 []int

func (h heap_MOETV2) Len() int { return len(h) }
func (h heap_MOETV2) Less(i, j int) bool { return h[i] < h[j] }
func (h heap_MOETV2) Swap(i, j int) { h[i], h[j] = h[j], h[i] }
func (h *heap_MOETV2) Push(a interface{}) { *h = append(*h, a.(int)) }
func (h *heap_MOETV2) Pop() interface{} { temp := *h; ans := temp[len(temp) - 1]; (*h) = temp[0:len(temp) - 1]; return ans }
