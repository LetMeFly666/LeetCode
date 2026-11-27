/*
 * @Author: LetMeFly
 * @Date: 2026-11-27 13:58:14
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-11-27 17:01:26
 */
import java.util.Arrays;

class Solution {
    public int removeCoveredIntervals(int[][] intervals) {
        Arrays.sort(intervals, (i, j) -> {
            return intervals[i][0] == intervals[j][0] ? intervals[j][1] - intervals[i][j] : intervals[i][0] - intervals[j][0];
        });
    }
}
