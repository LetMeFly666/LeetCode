/*
 * @Author: LetMeFly
 * @Date: 2025-03-21 15:34:47
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-21 16:32:51
 * @Description: Go int和int64的位运算似乎几乎一点都不会自动转换类型
 */
package main

func maximumOr(nums []int, k int) (ans int64) {
    allOr, all1 := 0, 0
    for _, t := range nums {
        all1 |= allOr & t
        allOr |= t
    }
    for _, t := range nums {
        ans = max(ans, int64(allOr) ^ int64(t) | int64(all1) | int64(t) << k)
    }
    return
}