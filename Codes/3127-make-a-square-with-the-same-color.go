/*
 * @Author: LetMeFly
 * @Date: 2024-08-31 17:28:10
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-08-31 17:37:07
 */
package main

func canMakeSquare(grid [][]byte) bool {
    for i := 1; i < len(grid); i++ {
        for j := 1; j < len(grid[0]); j++ {
            cntW := 0
            for x := -1; x < 1; x++ {
                for y := -1; y < 1; y++ {
                    if grid[i + x][j + y] == 'W' {
                        cntW++
                    }
                }
            }
            if cntW != 2 {
                return true
            }
        }
    }
    return false
}