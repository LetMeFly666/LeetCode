/*
 * @Author: LetMeFly
 * @Date: 2024-07-08 13:20:56
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-08 13:22:11
 */
package main

func pivotIndex(nums []int) int {
    sum := 0
    for _, t := range nums {
        sum += t
    }
    nowSum := 0
    for i, t := range nums {
        if sum - t == nowSum * 2 {
            return i
        }
        nowSum += t
    }
    return -1
}