/*
 * @Author: LetMeFly
 * @Date: 2026-10-23 21:05:27
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-23 21:15:04
 */
import java.util.Arrays;

class Solution {
    public int removeCoveredIntervals(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> {
            return a[0] == b[0] ? b[1] - a[1] : a[0] - b[0];
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
