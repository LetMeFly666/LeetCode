/*
 * @Author: LetMeFly
 * @Date: 2025-05-27 23:28:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-27 23:49:20
 */
package main

func maximumValueSum(nums []int, k int, edges [][]int) int64 {
    odd, even := int64(-10000000000000000), int64(0)  // -1...0也可能是int
    for _, t := range nums {
        odd, even = max(odd + int64(t), even + int64(t ^ k)), max(even + int64(t), odd + int64(t ^ k))
    }
    return even
}