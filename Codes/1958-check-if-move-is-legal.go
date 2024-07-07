/*
 * @Author: LetMeFly
 * @Date: 2024-07-07 17:11:00
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-07 17:15:37
 */
package main

func inBoard(x int, y int) bool {
    return 0 <= x && x < 8 && 0 <= y && y < 8
}

func checkMove(board [][]byte, rMove int, cMove int, color byte) bool {
    directions := []struct{x, y int}{{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}}
    for _, thisDirection := range directions {
        dx, dy := thisDirection.x, thisDirection.y
        x, y := rMove + dx, cMove + dy
        if !inBoard(x, y) || board[x][y] == '.' || board[x][y] == color {
            continue
        }
        for inBoard(x + dx, y + dy) {
            x, y = x + dx, y + dy
            if board[x][y] == color {
                return true
            }
            if board[x][y] == '.' {
                break
            }
        }
    }
    return false
}