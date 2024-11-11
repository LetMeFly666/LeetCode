/*
 * @Author: LetMeFly
 * @Date: 2024-11-09 10:15:35
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-09 10:19:36
 */
class NeighborSum {
    private static final int[][] direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    private int[][] cache;

    public NeighborSum(int[][] grid) {
        int n = grid.length;
        cache = new int[n * n][2];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 8; k++) {
                    int x = i + direction[k][0], y = j + direction[k][1];
                    if (x >= 0 && x < n && y >= 0 && y < n) {
                        cache[grid[i][j]][k / 4] += grid[x][y];
                    }
                }
            }
        }
    }
    
    public int adjacentSum(int value) {
        return cache[value][0];
    }
    
    public int diagonalSum(int value) {
        return cache[value][1];
    }
}

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum obj = new NeighborSum(grid);
 * int param_1 = obj.adjacentSum(value);
 * int param_2 = obj.diagonalSum(value);
 */