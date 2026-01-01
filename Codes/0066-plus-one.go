/*
 * @Author: LetMeFly
 * @Date: 2026-01-01 15:40:30
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-01 16:09:18
 */
package main

func plusOne(digits []int) []int {
    cnt := 1
    for i := len(digits) - 1; i >= 0; i-- {
        digits[i] += cnt
        cnt = digits[i] / 10
        digits[i] %= 10
    }
    if cnt > 0 {
        return append([]int{cnt}, digits...)
    }
    return digits
}