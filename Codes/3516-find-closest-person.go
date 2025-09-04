/*
 * @Author: LetMeFly
 * @Date: 2025-09-04 13:33:33
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-04 13:37:51
 */
package main

func findClosest(x int, y int, z int) int {
    diff := abs(x - z) - abs(y - z)
    if diff == 0 {
        return 0
    } else if diff > 0 {
        return 2
    }
    return 1
}