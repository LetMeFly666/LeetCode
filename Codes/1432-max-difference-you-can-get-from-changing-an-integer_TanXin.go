/*
 * @Author: LetMeFly
 * @Date: 2025-06-19 10:16:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-19 13:47:56
 */
package main

import (
	"strconv"
	"strings"
)

// M: !9->9
// m: first==1 ? !01->0 : first->1
func maxDiff(num int) int {
    s := string(num)
    M, m := num, num
    change := func(s string, a, b byte) int {
        ans, _ := strconv.Atoi(strings.ReplaceAll(s, string(a), string(b)))
        return ans
    }
    for i := range s {
        if s[i] != '9' {
            M = change(s, s[i], '9')
            break
        }
    }
    if s[0] == '1' {
        for i := range s {
            if s[i] > '1' {
                m = change(s, s[i], '0')
                break
            }
        }
    } else {
        m = change(s, s[0], '1')
    }
    return M - m
}