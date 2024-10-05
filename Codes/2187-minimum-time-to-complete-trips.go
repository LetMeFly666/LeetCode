/*
 * @Author: LetMeFly
 * @Date: 2024-10-05 18:23:30
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-05 18:27:03
 */
package main

func check(times []int, totalTrips int64, timeConsume int64) bool {
    for _, t := range times {
        totalTrips -= timeConsume / int64(t)
    }
    return totalTrips <= 0
}

func minimumTime(times []int, totalTrips int) int64 {
    l, r := int64(1), int64(1e14) + 1
    for l < r {
        mid := (l + r) >> 1
        if check(times, int64(totalTrips), mid) {
            r = mid
        } else {
            l = mid + 1
        }
    }
    return l
}