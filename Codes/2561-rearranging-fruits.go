/*
 * @Author: LetMeFly
 * @Date: 2025-08-03 22:53:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-04 13:38:44
 */
package main

import "sort"

func abs2561(x int) int {
    if x < 0 {
        return -x
    }
    return x
}

func minCost(basket1 []int, basket2 []int) (ans int64) {
    timeDiffs := map[int]int{}
    m := 1000000000
    for _, t := range basket1 {
        timeDiffs[t]++
        m = min(m, t)
    }
    for _, t := range basket2 {
        timeDiffs[t]--
        m = min(m, t)
    }
    
    change := []int{}
    for val, times := range timeDiffs {
        if times == 0 {
            continue
        }
        if times % 2 != 0 {
            return -1
        }
        for range abs2561(times) / 2 {  // 刚发现go还有这种语法呢
            change = append(change, val)
        }
    }

    sort.Ints(change)
    for i := 0; i < len(change) / 2; i++ {
        ans += int64(min(2 * m, change[i]))
    }
    return
}