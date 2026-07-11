/*
 * @Author: LetMeFly
 * @Date: 2026-07-11 07:59:33
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-11 08:08:28
 */
import java.util.Arrays;

class Solution {
    public int removeCoveredIntervals(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> {
            return a[0] == b[0] ? b[1] - a[1] : a[0] - b[0];
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
