/*
 * @Author: LetMeFly
 * @Date: 2024-09-04 12:42:15
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-09-04 13:12:53
 */
package main
import "sort"

func countWays(nums []int) int {
    sort.Ints(nums)
    ans := 1
    if nums[0] > 0 {
        ans++
    }
    for i := 1; i < len(nums); i++ {
        if i > nums[i - 1] && i < nums[i] {
            ans++
        }
    }
    return ans
}