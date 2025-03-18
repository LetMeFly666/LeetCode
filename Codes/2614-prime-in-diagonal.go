/*
 * @Author: LetMeFly
 * @Date: 2025-03-18 23:55:55
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-18 23:58:46
 */
package main

func isPrime2614(n int) (ans bool) {
    if n < 2 {
        return
    }
    for i := 2; i * i <= n; i++ {
        if n % i == 0 {
            return
        }
    }
    return true
}

func diagonalPrime(nums [][]int) (ans int) {
    for i := range nums {
        if isPrime2614(nums[i][i]) {
            ans = max(ans, nums[i][i])
        }
        if isPrime2614(nums[i][len(nums) - i - 1]) {
            ans = max(ans, nums[i][len(nums) - i - 1])
        }
    }
    return
}