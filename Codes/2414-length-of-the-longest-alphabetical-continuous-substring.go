/*
 * @Author: LetMeFly
 * @Date: 2024-09-19 17:52:33
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-09-19 17:56:59
 */
package main

func longestContinuousSubstring(s string) int {
    ans, nowCnt := 1, 1
    for i := 1; i < len(s); i++ {
        if s[i] == s[i - 1] + 1 {
            nowCnt++
            if nowCnt > ans {
                ans = nowCnt
            }
        } else {
            nowCnt = 1
        }
    }
    return ans
}