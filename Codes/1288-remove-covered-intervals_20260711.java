/*
 * @Author: LetMeFly
 * @Date: 2026-07-11 07:59:33
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-11 08:06:01
 */
import java.util.Arrays;

class Solution {
    public int removeCoveredIntervals(int[][] intervals) {
        Arrays.sort(intervals, (i, j) -> {
            return intervals[i][0] == intervals[j][0] ? intervals[j][1] - intervals[i][1] : intervals[i][0] - intervals[j][0];
        });
        int ans = intervals.length;
        int maxr = 0;
        for (int[] v : intervals) {
            if (v[1] <= maxr) {
                ans--;
            } else {
                maxr = v[1];
            }
        }
        return ans;
    }
}
