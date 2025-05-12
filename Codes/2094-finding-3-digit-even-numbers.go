/*
 * @Author: LetMeFly
 * @Date: 2025-05-12 21:58:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-12 22:43:11
 */
package main

func findEvenNumbers(digits []int) []int {
    times := make([]int, 10)
    for _, d := range digits {
        times[d]++
    }
    ans := make([]int, 0)
    for i := 100; i < 1000; i++ {
        thisTimes := make([]int, 10)
        for tmp := i; tmp > 0; tmp /= 10 {
            thisTimes[tmp % 10]++
        }
        ok := true
        for j := range times {
            if thisTimes[j] > times[j] {
                ok = false
                break
            }
        }
        if ok {
            ans = append(ans, i)
        }
    }
    return ans
}