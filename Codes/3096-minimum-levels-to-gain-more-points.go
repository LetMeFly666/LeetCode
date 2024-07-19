/*
 * @Author: LetMeFly
 * @Date: 2024-07-19 16:13:21
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-19 16:14:05
 */
package main

func addScore(x int) int {
    if x == 0 {
        return -1
    }
    return 1
}

func minimumLevels(possible []int) int {
    cnt := 0
    for _, t := range possible {
        cnt += addScore(t)
    }
    now := 0
    for i := 0; i < len(possible) - 1; i++ {
        now += addScore(possible[i])
        if now > cnt - now {
            return i + 1
        }
    }
    return -1
}