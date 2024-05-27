/*
 * @Author: LetMeFly
 * @Date: 2024-05-27 21:49:25
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-05-27 21:56:35
 */
package main

func missingRolls(rolls []int, mean int, n int) []int {
    target := mean * (len(rolls) + n)
    for i := 0; i < len(rolls); i++ {
        target -= rolls[i];
    }
    if target < n || target > n * 6 {
        return make([]int, 0)
    }
    ans := make([]int, n)
    mean2, remain := target / n, target % n
    for i := 0; i < n; i++ {
        ans[i] = mean2
        if i < remain {
            ans[i]++
        }
    }
    return ans
}