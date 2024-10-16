/*
 * @Author: LetMeFly
 * @Date: 2024-10-16 23:11:25
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-16 23:13:40
 */
package main
import "sort"

func minimumAverage(nums []int) float64 {
    sort.Ints(nums)
    ans := 1000
    for i := 0; i < len(nums) / 2; i++ {
        ans = min(ans, nums[i] + nums[len(nums) - i - 1])
    }
    return float64(ans) / 2
}