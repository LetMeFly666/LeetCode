/*
 * @Author: LetMeFly
 * @Date: 2024-06-06 22:44:04
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-06 22:44:22
 */
package main

func minimumSteps(s string) int64 {
    ans, times := int64(0), 0
    for _, c := range s {
        if c == '1' {
            times++
        } else {  // 必须和上一个大括号写在同一行
            ans += int64(times)
        }
    }
    return ans
}