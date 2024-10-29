/*
 * @Author: LetMeFly
 * @Date: 2024-10-29 23:39:33
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-29 23:41:47
 */
package main

import "fmt"

func validStrings(n int) []string {
    ans := make([]string, 0)
    mask := (1 << n) - 1
    for i := 0; i < (1 << n); i++ {
        x := i ^ mask
        if (x & (x >> 1) == 0) {
            ans = append(ans, fmt.Sprintf("%0*b", n, i))
        }
    }
    return ans
}