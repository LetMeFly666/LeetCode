/*
 * @Author: LetMeFly
 * @Date: 2024-06-16 18:20:10
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-16 18:20:12
 */
package main

func findLUSlength(a string, b string) int {
    if a == b {
        return -1
    } else {
        if len(a) > len(b) {
            return len(a)
        } else {
            return len(b)
        }
    }
}