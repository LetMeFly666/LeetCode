/*
 * @Author: LetMeFly
 * @Date: 2024-05-28 22:19:06
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-05-28 22:19:32
 */
package main

func findPeaks(mountain []int) []int {
    ans := make([]int, 0)
    for i := 1; i < len(mountain) - 1; i++ {
        if mountain[i] > mountain[i - 1] && mountain[i] > mountain[i + 1] {
            ans = append(ans, i)
            i++
        }
    }
    return ans
}