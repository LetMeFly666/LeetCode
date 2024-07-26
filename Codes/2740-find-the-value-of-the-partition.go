/*
 * @Author: LetMeFly
 * @Date: 2024-07-26 15:25:06
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-26 15:27:35
 */
package main

import "sort"

func min(a int, b int) int {
    if a <= b {
        return a
    }
    return b
}

func abs(a int) int {
    if a >= 0 {
        return a
    }
    return -a
}

func findValueOfPartition(nums []int) int {
    sort.Ints(nums);
    ans := 1000000000;
    for i := 1; i < len(nums); i++ {
        ans = min(ans, abs(nums[i] - nums[i - 1]))
    }
    return ans;
}