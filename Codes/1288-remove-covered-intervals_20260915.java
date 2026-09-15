/*
 * @Author: LetMeFly
 * @Date: 2026-09-15 17:12:02
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-15 17:25:48
 */
import java.util.Arrays;

class Solution {
    public int removeCoveredIntervals(int[][] intervals) {
        Arrays.sort(intervals, (i, j) -> {
            return intervals[i][0] == intervals[j][0] ? intervals[j][1] - intervals[i][1] : intervals[i][0] - intervals[j][0];
        });
        int ans = intervals.length;
        int maxr = -1;
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
