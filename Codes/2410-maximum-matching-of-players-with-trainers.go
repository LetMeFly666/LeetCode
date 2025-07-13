/*
 * @Author: LetMeFly
 * @Date: 2025-07-13 16:44:48
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-13 17:08:39
 */
package main

import "sort"

func matchPlayersAndTrainers(players []int, trainers []int) (ans int) {
    sort.Ints(players)
    sort.Ints(trainers)
    for p, t := 0, 0; p < len(players) && t < len(trainers); t++ {
        if trainers[t] >= players[p] {
            ans++
            p++
        }
    }
    return
}