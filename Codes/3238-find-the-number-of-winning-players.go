/*
 * @Author: LetMeFly
 * @Date: 2024-11-23 10:18:49
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-23 10:22:10
 */
package main

func winningPlayerCount(n int, pick [][]int) (ans int) {
    cnt := make([][]int, n)
    for th := range cnt {
        cnt[th] = make([]int, 11)
    }
    for _, p := range pick {
        cnt[p[0]][p[1]]++
    }
    for i, row := range cnt {
        for _, val := range row {
            if val > i {
                ans++
                break
            }
        }
    }
    return
}