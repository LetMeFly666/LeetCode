/*
 * @Author: LetMeFly
 * @Date: 2025-01-06 20:41:20
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-06 20:43:19
 */
package main
import "sort"

func max_MCFWSF(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func maxConsecutive(bottom int, top int, special []int) (ans int) {
    sort.Ints(special)
    ans = max_MCFWSF(special[0] - bottom, top - special[len(special) - 1])
    for i := 1; i < len(special); i++ {
        ans = max_MCFWSF(ans, special[i] - special[i - 1] - 1)
    }
    return
}