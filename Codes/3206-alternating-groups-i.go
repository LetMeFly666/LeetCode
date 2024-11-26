/*
 * @Author: LetMeFly
 * @Date: 2024-11-26 23:35:39
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-26 23:40:05
 */
package main

func numberOfAlternatingGroups(colors []int) (ans int) {
    for i := range colors {
        if colors[i] != colors[(i + 1) % len(colors)] && colors[i] == colors[(i + 2) % len(colors)] {
            ans++
        }
    }
    return
}