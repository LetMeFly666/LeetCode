/*
 * @Author: LetMeFly
 * @Date: 2026-11-27 13:58:14
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-11-27 17:03:47
 */
import java.util.Arrays;

class Solution {
    public int removeCoveredIntervals(int[][] intervals) {
        Arrays.sort(intervals, (x, y) -> {
            return x[0] == y[0] ? y[1] - x[1] : x[0] - y[0];
        });
        int ans = intervals.length;
        int maxr = 0;
        for (int[] p : intervals) {
            if (p[1] <= maxr) {
                ans--;
            } else {
                maxr = p[1];
            }
        }
        return ans;
    }
}
