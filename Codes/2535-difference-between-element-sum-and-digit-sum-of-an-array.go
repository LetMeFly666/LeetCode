/*
 * @Author: LetMeFly
 * @Date: 2024-09-26 18:07:27
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-09-26 18:13:38
 */
package main

func abs(x int) int {
    if x >= 0 {
        return x
    }
    return -x
}

func getSum(x int) int {
    ans := 0
    for x > 0 {
        ans += x % 10
        x /= 10
    }
    return ans
}

func differenceOfSum(nums []int) int {
    x, y := 0, 0
    for _, t := range nums {
        x += t
        y += getSum(t)
    }
    return abs(x - y)
}