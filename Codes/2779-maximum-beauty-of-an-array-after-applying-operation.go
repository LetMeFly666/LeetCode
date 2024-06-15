/*
 * @Author: LetMeFly
 * @Date: 2024-06-15 19:13:52
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-15 19:16:45
 */
package main

import "sort"

func maximumBeauty(nums []int, k int) int {
    ans := 0
    sort.Ints(nums)
    k *= 2
    for l, r := 0, 0; r < len(nums); r++ {
        for ; nums[r] - nums[l] > k; {
            l++
        }
        if r - l + 1 > ans {
            ans = r - l + 1
        }
    }
    return ans
}