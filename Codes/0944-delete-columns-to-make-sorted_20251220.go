/*
 * @Author: LetMeFly
 * @Date: 2025-12-20 22:44:28
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-20 22:58:23
 */
package main

func minDeletionSize(strs []string) (ans int) {
    n:= len(strs)
    for j := range strs[0] {
        for i := 1; i < n; i++ {
            if strs[i][j] < strs[i-1][j] {
                ans++
                break
            }
        }
    }
    return
}