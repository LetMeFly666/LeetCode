/*
 * @Author: LetMeFly
 * @Date: 2024-07-07 17:06:08
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-07 17:10:25
 */
class Solution {
    private static final int[][] directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

    private boolean inBoard(int x, int y) {
        return x >= 0 && x < 8 && y >= 0 && y < 8;
    }

    public boolean checkMove(char[][] board, int rMove, int cMove, char color) {
        for (int d = 0; d < 8; d++) {
            int dx = directions[d][0], dy = directions[d][1];
            int x = rMove + dx, y = cMove + dy;
            if (!inBoard(x, y) || board[x][y] == '.' || board[x][y] == color) {
                continue;
            }
            while (inBoard(x + dx, y + dy)) {
                x = x + dx;
                y = y + dy;
                if (board[x][y] == color) {
                    return true;
                }
                if (board[x][y] == '.') {
                    break;
                }
            }
        }
        return false;
    }
}