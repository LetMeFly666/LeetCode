/*
 * @Author: LetMeFly
 * @Date: 2025-04-20 21:04:11
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-20 21:05:23
 */
package main

func numRabbits(answers []int) (ans int) {
    times := map[int]int{}
    for _, v := range answers {
        times[v]++
    }
    for group, total := range times {
        ans += (total + group) / (group + 1) * (group + 1)
    }
    return
}