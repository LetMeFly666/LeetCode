/*
 * @Author: LetMeFly
 * @Date: 2025-05-11 14:00:52
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-11 14:19:31
 */
package main

func threeConsecutiveOdds(arr []int) bool {
    for i := 2; i < len(arr); i++ {
        if arr[i] % 2 == 1 && arr[i - 1] % 2 == 1 && arr[i - 2] % 2 == 1 {
            return true
        }
    }
    return false;
}