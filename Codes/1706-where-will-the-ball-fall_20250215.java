/*
 * @Author: LetMeFly
 * @Date: 2025-02-15 11:20:57
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-15 11:30:31
 */
class Solution {
    private int[][] grid;

    private int drop(int y) {
        for (int x = 0; x < grid.length; x++) {
            int nextY = grid[x][y] + y;
            if (nextY < 0 || nextY >= grid[0].length || grid[x][y] != grid[x][nextY]) {
                return -1;
            }
            y = nextY;
        }
        return y;
    }

    public int[] findBall(int[][] grid) {
        this.grid = grid;
        int[] ans = new int[grid[0].length];
        for (int j = 0; j < grid[0].length; j++) {
            ans[j] = drop(j);
        }
        return ans;
    }
}