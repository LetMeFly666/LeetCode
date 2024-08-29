/*
 * @Author: LetMeFly
 * @Date: 2024-08-29 23:19:44
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-08-29 23:21:31
 */
class Solution {
    public boolean satisfiesConditions(int[][] grid) {
        for (int j = 0; j < grid[0].length; j++) {
            if (j > 0 && grid[0][j] == grid[0][j - 1]) {
                return false;
            }
            for (int i = 1; i < grid.length; i++) {
                if (grid[i][j] != grid[i - 1][j]) {
                    return false;
                }
            }
        }
        return true;
    }
}