/*
 * @Author: LetMeFly
 * @Date: 2024-11-04 19:49:27
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-04 19:52:23
 */
package main
import "math"

func judgeSquareSum(c int) bool {
    for a := int(math.Sqrt(float64(c))); a >= 0; a-- {
        b := int(math.Sqrt(float64(c - a * a)))
        if a * a + b * b == c {
            return true
        }
    }
    return false
}