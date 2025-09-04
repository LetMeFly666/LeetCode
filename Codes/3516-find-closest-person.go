/*
 * @Author: LetMeFly
 * @Date: 2025-09-04 13:33:33
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-04 13:39:11
 */
package main

func abs3516(a int) int {
    if a < 0 {
        return -a
    }
    return a
}

func findClosest(x int, y int, z int) int {
    diff := abs3516(x - z) - abs3516(y - z)
    if diff == 0 {
        return 0
    } else if diff > 0 {
        return 2
    }
    return 1
}