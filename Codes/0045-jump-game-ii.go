/*
 * @Author: LetMeFly
 * @Date: 2025-01-27 07:57:23
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-27 07:58:38
 */
package main

func jump(nums []int) (ans int) {
    var nowMax, nextMax int
    for i, l := range nums[:len(nums) - 1] {
        nextMax = max(nextMax, i + l)
        if nowMax == i {
            nowMax = nextMax
            ans++
        }
    }
    return
}