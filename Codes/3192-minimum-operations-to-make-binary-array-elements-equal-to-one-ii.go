/*
 * @Author: LetMeFly
 * @Date: 2024-10-19 09:28:57
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-19 09:29:58
 */
package main

func minOperations(nums []int) int {
    ans, original := 0, 1
    for _, t := range nums {
        if t ^ original == 1 {
            ans++
            original ^= 1
        }
    }
    return ans
}