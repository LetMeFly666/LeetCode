/*
 * @Author: LetMeFly
 * @Date: 2025-02-17 14:39:01
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-17 14:47:00
 */
package main

func findSpecialInteger(arr []int) int {
    locDiff := len(arr) / 4
    for i := 0; true; i++ {
        if arr[i] == arr[i + locDiff] {
            return arr[i]
        }
    }
    return -1  // Fake Return - 及时上面是for true也需要return
}