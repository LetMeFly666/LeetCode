/*
 * @Author: LetMeFly
 * @Date: 2025-03-28 13:32:55
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-28 13:34:00
 */
package main

import "math/bits"

func minimizedStringLength(s string) int {
    mask := uint(0)
    for _, c := range s {
        mask |= 1 << (c - 'a')
    }
    return bits.OnesCount(mask)
}