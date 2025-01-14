/*
 * @Author: LetMeFly
 * @Date: 2025-01-14 17:17:36
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-14 17:18:45
 */
package main

func largestCombination(candidates []int) (ans int) {
    for i := 0; i < 24; i++ {
        cnt := 0
        for _, t := range candidates {
            cnt += t >> i & 1
        }
        if cnt > ans {
            ans = cnt
        }
    }
    return ans
}