/*
 * @Author: LetMeFly
 * @Date: 2025-01-08 15:43:44
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-08 15:46:23
 */
package main

func largestGoodInteger(num string) string {
    M := byte('/')
    for i := 2; i < len(num); i++ {
        if num[i] > M && num[i] == num[i - 1] && num[i] == num[i - 2] {
            M = num[i]
        }
    }
    if M == '/' {
        return ""
    }
    return string(M) + string(M) + string(M)
}