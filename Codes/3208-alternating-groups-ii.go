/*
 * @Author: LetMeFly
 * @Date: 2024-11-28 23:38:58
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-28 23:41:29
 */
package main

func numberOfAlternatingGroups(colors []int, k int) (ans int) {
    cntDiff := 0
    for i := 1; i < k; i++ {
        if colors[i] != colors[i - 1] {
            cntDiff++
        }
    }
    for i := range colors {
        if cntDiff == k - 1 {
            ans++
        }
        if colors[(i + k) % len(colors)] != colors[(i + k - 1) % len(colors)] {
            cntDiff++
        }
        if colors[(i + 1) % len(colors)] != colors[i] {
            cntDiff--
        }
    }
    return
}