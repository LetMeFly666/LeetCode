/*
 * @Author: LetMeFly
 * @Date: 2025-05-27 23:28:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-27 23:48:05
 */
package main

func maximumValueSum(nums []int, k int, edges [][]int) int64 {
    odd, even := -10000000000000000, int64(0)
    for _, t := range nums {
        odd, even = max(odd + int64(t), even + int64(t ^ k)), max(even + int64(t), odd + int64(t ^ k))
    }
    return even
}