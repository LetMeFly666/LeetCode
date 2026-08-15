/*
 * @Author: LetMeFly
 * @Date: 2026-08-15 09:52:55
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-08-15 10:22:55
 */
import java.util.Arrays;

class Solution {
    public int removeCoveredIntervals(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> {
            a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        })
        int ans = intervals.length, maxr = 0;
        for (int[] p : intervals) {
            if (maxr >= p[1]) {
                ans--;
            } else {
                maxr = p[1];
            }
        }
        return ans;
    }
}
