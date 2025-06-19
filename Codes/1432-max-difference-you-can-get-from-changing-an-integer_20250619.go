/*
 * @Author: LetMeFly
 * @Date: 2025-06-19 10:16:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-19 13:38:19
 */
package main

// M: !9->9
// m: first==1 ? !01->0 : first->1
func maxDiff(num int) int {
    s := string(num)
    var M, m int
    change := func(s string, a, b byte) int {
        for i := range s {
            if s[i] == a {
                s[i] = b
            }
        }
    }
}