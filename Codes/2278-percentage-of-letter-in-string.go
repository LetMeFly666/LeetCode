/*
 * @Author: LetMeFly
 * @Date: 2025-03-31 13:32:03
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-31 13:32:19
 */
package main

import "strings"

func percentageLetter(s string, letter byte) int {
    return strings.Count(s, string(letter)) * 100 / len(s)
}