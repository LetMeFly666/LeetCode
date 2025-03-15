/*
 * @Author: LetMeFly
 * @Date: 2025-03-15 10:29:29
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-15 10:32:20
 */
package main

func abs3110(a int) int {
    if a < 0 {
        return -a
    }
    return a
}

func scoreOfString(s string) (ans int) {
    for i := 1; i < len(s); i++ {
        ans += abs3110(int(s[i]) - int(s[i - 1]))
    }
    return
}