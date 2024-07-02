/*
 * @Author: LetMeFly
 * @Date: 2024-07-02 10:50:23
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-02 10:55:49
 */
package main

func max(a int, b int) int {
    if a > b {
        return a
    }
    return b
}

func min(a int, b int) int {
    if a < b {
        return a
    }
    return b
}

func isPrime(n int) bool {
    if n == 1 {
        return false
    }
    for i := 2; i * i <= n; i++ {
        if n % i == 0 {
            return false
        }
    }
    return true
}

func maximumPrimeDifference(nums []int) int {
    M, m := -1, 10000000
    for i := 0; i < len(nums); i++ {
        if isPrime(nums[i]) {
            M = max(M, i)
            m = min(m, i)
        }
    }
    return M - m
}