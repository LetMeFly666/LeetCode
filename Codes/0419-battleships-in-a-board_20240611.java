/*
 * @Author: LetMeFly
 * @Date: 2024-06-11 12:22:38
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-11 12:24:00
 */
class Solution {
    public int countBattleships(char[][] board) {
        int ans = 0;
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (board[i][j] == 'X' && (i == 0 || board[i - 1][j] == '.') && (j == 0 || board[i][j - 1] == '.')) {
                    ans++;
                }
            }
        }
        return ans;
    }
}