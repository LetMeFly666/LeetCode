/*
 * @Author: LetMeFly
 * @Date: 2025-12-10 22:34:20
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-10 23:00:19
 */
package main

const MOD3577 int = 1000000007

func countPermutations(complexity []int) int {
    ans := 1
    for i := 1; i < len(complexity); i++ {
        if complexity[i] <= complexity[0] {
            return 0
        }
        ans = ans * i % MOD3577
    }
    return ans
}