/*
 * @Author: LetMeFly
 * @Date: 2024-05-25 12:44:32
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-05-25 12:55:00
 */
package main

func abs(x int) int {
    if x >= 0 {
        return x;
    }
    return -x;
}

func findIndices(nums []int, indexDifference int, valueDifference int) []int {
    for i := 0; i < len(nums); i++ {
        for j := i; j < len(nums); j++ {
            if j - i >= indexDifference && abs(nums[i] - nums[j]) >= valueDifference {
                return []int {i, j};
            }
        }
    }
    return []int {-1, -1};
}
