/*
 * @Author: LetMeFly
 * @Date: 2026-01-12 23:24:06
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-12 23:32:59
 */
class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {
        int ans = 0;
        for (int i = 1; i < points.length; i++) {
            ans += Math.max(Math.abs(points[i][0] - points[i - 1][0]) , Math.abs(points[i][1] - points[i - 1][1]));
        }
        return ans;
    }
}