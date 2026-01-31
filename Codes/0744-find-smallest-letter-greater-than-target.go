/*
 * @Author: LetMeFly
 * @Date: 2026-01-31 13:49:56
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-31 13:59:57
 */
package main

func nextGreatestLetter(letters []byte, target byte) byte {
    for _, c := range letters {
        if c > target {
            return c
        }
    }
    return letters[0]
}