/*
 * @Author: LetMeFly
 * @Date: 2024-12-24 19:07:32
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-24 23:43:52
 */
package main
import "container/heap"

type pair struct{ rotDay, appleNum int}
type PQ []pair

func (pq PQ) Len() int           { return len(pq) }
func (pq PQ) Less(i, j int) bool { return pq[i].rotDay < pq[j].rotDay }
func (pq PQ) Swap(i, j int)      { pq[i], pq[j] = pq[j], pq[i] }
func (pq *PQ) Push(v any)        { *pq = append(*pq, v.(pair)) }
func (pq *PQ) Pop() any          { v := (*pq)[len(*pq) - 1]; *pq = (*pq)[:len(*pq) - 1]; return v }

func min_eatenApples(a, b int) int { if a < b { return a}; return b}
func max_eatenApples(a, b int) int { if a > b { return a}; return b}

func eatenApples(apples []int, days []int) (ans int) {
    var pq PQ
    for day := range apples {
        if apples[day] > 0 {
            heap.Push(&pq, pair{day + days[day], apples[day]})
        }
        for len(pq) > 0 {
            v := heap.Pop(&pq).(pair)
            rotDay, appleNum := v.rotDay, v.appleNum
            if rotDay <= day {
                continue
            }
            ans++
            appleNum--
            if appleNum > 0 {
                heap.Push(&pq, pair{rotDay, appleNum})
            }
            break
        }
    }
    day := len(apples)
    for len(pq) > 0 {
        v := heap.Pop(&pq).(pair)
        rotDay, appleNum := v.rotDay, v.appleNum
        eat := max_eatenApples(0, min_eatenApples(rotDay - day, appleNum))
        ans += eat
        day += eat
    }
    return
}