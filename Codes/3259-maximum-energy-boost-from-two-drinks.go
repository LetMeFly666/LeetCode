/*
 * @Author: LetMeFly
 * @Date: 2024-11-01 12:36:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-01 12:41:05
 */
package main

func max(a int64, b int64) int64 {
    if a > b {
        return a
    }
    return b
}

func maxEnergyBoost(energyDrinkA []int, energyDrinkB []int) int64 {
    var day0a, day0b, day1a, day1b int64 = 0, 0, int64(energyDrinkA[0]), int64(energyDrinkB[0])
    for i := 1; i < len(energyDrinkA); i++ {
        day0a, day0b, day1a, day1b = day1a, day1b, max(day1a, day0b) + int64(energyDrinkA[i]), max(day0a, day1b) + int64(energyDrinkB[i])
    }
    return max(day1a, day1b)
}