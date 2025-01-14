/*
 * @Author: LetMeFly
 * @Date: 2025-01-14 12:32:44
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-14 12:33:14
 */
package main

func minOperations(nums []int, k int) (ans int) {
    for _, t := range nums {
        if t < k {
            ans++
        }
    }
    return
}