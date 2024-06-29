/*
 * @Author: LetMeFly
 * @Date: 2024-06-29 17:17:36
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-29 17:18:42
 */
package main

func removeTrailingZeros(num string) string {
    loc := len(num) - 1
    for num[loc] == '0' {
        loc--
    }
    return num[0 : loc + 1]
}