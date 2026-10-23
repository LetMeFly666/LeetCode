/*
 * @Author: LetMeFly
 * @Date: 2026-10-23 21:05:27
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-23 21:13:34
 */
import java.util.Arrays;

class Solution {
    public int removeCoveredIntervals(int[][] intervals) {
        Arrays.sort(intervals, (i, j) -> {
            return intervals[i][0] == intervals[j][0] ? intervals[j][1] - intervals[i][1] : 
        });
    }
}
