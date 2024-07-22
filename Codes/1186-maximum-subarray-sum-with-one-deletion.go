/*
 * @Author: LetMeFly
 * @Date: 2024-07-21 19:19:04
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-21 19:20:12
 */
package main

func max2(a int, b int) int {
    if a > b {
        return a
    }
    return b
}

func max3(a int, b int, c int) int {
    return max2(a, max2(b, c))
}

func maximumSum(arr []int) int {
    del0, del1, ans := arr[0], 0, arr[0]
    for i := 1; i < len(arr); i++ {
        del1 = max2(del1 + arr[i], del0)
        del0 = max2(del0 + arr[i], arr[i])
        ans = max3(ans, del0, del1)
    }
    return ans
}