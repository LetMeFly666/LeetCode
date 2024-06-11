/*
 * @Author: LetMeFly
 * @Date: 2024-06-11 12:24:27
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-11 12:26:00
 */
package main

func countBattleships(board [][]byte) int {
    ans := 0
    for i := 0; i < len(board); i++ {
        for j := 0; j < len(board[0]); j++ {
            if board[i][j] == 'X' && (i == 0 || board[i - 1][j] == '.') && (j == 0 || board[i][j - 1] == '.') {
                ans++
            }
        }
    }
    return ans
}