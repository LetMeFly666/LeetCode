/*
 * @Author: LetMeFly
 * @Date: 2025-12-08 18:40:41
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-08 18:57:02
 */
package main

import "math"

func countTriples(n int) (ans int) {
    for a := 1; a <= n; a++ {
        for b := 1; b <= n; b++ {
            k := a * a + b * b
            c := int(math.Sqrt(float64(k)))
            if c <= n && c * c == k {
                ans++
            }
        }
    }
    return
}