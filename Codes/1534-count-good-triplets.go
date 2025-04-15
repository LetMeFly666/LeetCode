/*
 * @Author: LetMeFly
 * @Date: 2025-04-15 10:39:01
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-15 10:43:14
 */
package main

func abs1534(a int) int {
    if a < 0 {
        return -a
    }
    return a
}

func countGoodTriplets(arr []int, a int, b int, c int) (ans int) {
    for i := range arr {
        for j := i + 1; j < len(arr); j++ {
            for k := j + 1; k < len(arr); k++ {
                if abs1534(arr[i] - arr[j]) <= a && abs1534(arr[j] - arr[k]) <= b && abs1534(arr[i] - arr[k]) <= c {
                    ans++
                }
            }
        }
    }
    return
}