/*
 * @Author: LetMeFly
 * @Date: 2024-09-03 18:24:08
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-09-03 18:59:19
 */
package main

func min(a int64, b int64) int64 {
    if a < b {
        return a
    }
    return b
}

func min4(a int64, b int64, c int64, d int64) int64 {
    return min(a, min(b, min(c, d)))
}

func max(a int64, b int64) int64 {
    if a > b {
        return a
    }
    return b
}

func max4(a int64, b int64, c int64, d int64) int64 {
    return max(a, max(b, max(c, d)))
}

func maxStrength(nums []int) int64 {
    m, M := (int64)(nums[0]), int64(nums[0])
    for i := 1; i < len(nums); i++ {
        m, M = min4(m, (int64)(nums[i]), m * (int64)(nums[i]), M * (int64)(nums[i])),
               max4(M, (int64)(nums[i]), m * (int64)(nums[i]), M * (int64)(nums[i]))
    }
    return M
}