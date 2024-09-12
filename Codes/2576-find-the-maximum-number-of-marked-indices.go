/*
 * @Author: LetMeFly
 * @Date: 2024-09-12 21:21:27
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-09-12 21:40:51
 */
package main
import "sort"

func maxNumOfMarkedIndices(nums []int) int {
    sort.Ints(nums)
    ans := 0
    for l, r := 0, (len(nums) + 1) / 2; r < len(nums); r++ {
        if nums[l] * 2 <= nums[r] {
            ans += 2
            l++
        }
    }
    return ans
}