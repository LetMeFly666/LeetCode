/*
 * @Author: LetMeFly
 * @Date: 2025-02-20 11:06:49
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-20 11:18:27
 */
package main

func evenOddBit(n int) []int {
    ans := make([]int, 2)
    for index := 0; n > 0; n >>= 1 {
        ans[index] += n & 1
        index ^= 1
    }
    return ans
}