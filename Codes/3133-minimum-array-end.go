/*
 * @Author: LetMeFly
 * @Date: 2024-08-22 23:16:33
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-08-22 23:20:15
 */
package main

func minEnd(n int, x int) int64 {
    n64, ans := (int64)(n - 1), (int64)(x)
    for in, ix := 0, 0; in < 27; in, ix = in + 1, ix + 1 {
        for ((ans >> ix) & 1) != 0 {
            ix++
        }
        ans |= (((n64 >> in) & 1) << ix)
    }
    return ans
}