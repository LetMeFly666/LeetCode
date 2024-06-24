/*
 * @Author: LetMeFly
 * @Date: 2024-06-24 13:00:18
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-24 13:05:18
 */
package main

func nextGreaterElements(nums []int) []int {
    ans := make([]int, len(nums))
    for i := range ans {
        ans[i] = -1
    }
    st := []int{}
    for i := 0; i < len(nums) * 2; i++ {
        th := i % len(nums)
        for len(st) > 0 && nums[st[len(st) - 1]] < nums[th] {
            ans[st[len(st) - 1]] = nums[th]
            st = st[:len(st) - 1]
        }
        st = append(st, th)
    }
    return ans
}