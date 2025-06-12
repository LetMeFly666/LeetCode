/*
 * @Author: LetMeFly
 * @Date: 2025-06-12 22:49:40
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-12 22:58:57
 * @Descriptions: AC,100.00%,93.33%
 */
package main

// abs3423 是因为golang没有内置abs函数
func abs3423(x int) int {
    if x < 0 {
        return -x
    }
    return x
}

func maxAdjacentDistance(nums []int) int {
    ans := abs3423(nums[0] - nums[len(nums)-1])
    for i := 1; i < len(nums); i++ {
        ans = max(ans, abs3423(nums[i] - nums[i - 1]))
    }
    return ans
}