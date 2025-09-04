/*
 * @Author: LetMeFly
 * @Date: 2025-09-02 20:09:04
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-02 20:14:52
 */
class Solution {
    private int[][] points;

    private boolean check(int i, int j) {
        return points[i][0] <= points[j][0] && points[i][1] >= points[j][1];
    }

    private boolean check(int i, int j, int k) {
        return !(points[i][0] <= points[k][0] && points[k][0] <= points[j][0] && points[i][1] >= points[k][1] && points[k][1] >= points[j][1]);
    }

    public int numberOfPairs(int[][] points) {
        int ans = 0;
        this.points = points;
        for (int i = 0; i < points.length; i++) {
            for (int j = 0; j < points.length; j++) {
                if (i == j) {
                    continue;
                }
                if (!check(i, j)) {
                    continue;
                }
                boolean can = true;
                for (int k = 0; k < points.length; k++) {
                    if (k == i || k == j) {
                        continue;
                    }
                    if (!check(i, j, k)) {
                        can = false;
                        break;
                    }
                }
                if (can) {
                    ans ++;
                }
            }
        }
        return ans;
    }
}