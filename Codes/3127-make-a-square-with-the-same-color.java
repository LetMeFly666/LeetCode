/*
 * @Author: LetMeFly
 * @Date: 2024-08-31 17:27:59
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-08-31 17:35:46
 */
class Solution {
    public boolean canMakeSquare(char[][] grid) {
        for (int i = 1; i < grid.length; i++) {
            for (int j = 1; j < grid[0].length; j++) {
                int cntW = 0;
                for (int x = -1; x < 1; x++) {
                    for (int y = -1; y < 1; y++) {
                        if (grid[i + x][j + y] == 'W') {
                            cntW++;
                        }
                    }
                }
                if (cntW != 2) {
                    return true;
                }
            }
        }
        return false;
    }
}