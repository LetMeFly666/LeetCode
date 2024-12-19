/*
 * @Author: LetMeFly
 * @Date: 2024-12-19 16:29:10
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-19 16:29:28
 */
package main

func stableMountains(height []int, threshold int) (ans []int) {
    for i := 1; i < len(height); i++ {
        if height[i - 1] > threshold {
            ans = append(ans, i)
        }
    }
    return
}