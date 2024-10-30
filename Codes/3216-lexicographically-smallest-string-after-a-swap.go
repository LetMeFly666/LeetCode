/*
 * @Author: LetMeFly
 * @Date: 2024-10-30 12:45:43
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-30 12:47:12
 */
package main

func getSmallestString(s string) string {
    temp := []byte(s)
    for i := 1; i < len(s); i++ {
        if s[i - 1] > s[i] && s[i - 1] % 2 == s[i] % 2 {
            temp[i - 1], temp[i] = s[i], s[i - 1]
            return string(temp)
        }
    }
    return s
}