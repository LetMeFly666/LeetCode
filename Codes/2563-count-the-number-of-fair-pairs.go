/*
 * @Author: LetMeFly
 * @Date: 2025-04-19 16:24:24
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-19 16:43:06
 */
package main
import (
    "sort"
)

func countFairPairs(nums []int, lower int, upper int) (ans int64) {
    sort.Ints(nums)
    for i, v := range nums {
        l := sort.Search(len(nums), func(x int) bool {return x > i && nums[x] >= lower - v})
        r := sort.Search(len(nums), func(x int) bool {return x > i && nums[x] >= upper - v + 1})
        ans += int64(r - l)
    }
    return
}