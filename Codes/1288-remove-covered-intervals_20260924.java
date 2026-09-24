/*
 * @Author: LetMeFly
 * @Date: 2026-09-24 12:11:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-24 12:20:59
 */
import java.util.Arrays;

class Solution {
    public int removeCoveredIntervals(int[][] intervals) {
        Arrays.sort(intervals, (i, j) -> {
            return a[0] == b[0] ? b[1] - a[1] : a[0] - b[0];
        })
        int ans = intervals.length;
        int maxr = -1;
        for (int[] v : intervals) {
            if (maxr >= v[1]) {
                ans--;
            } else {
                maxr = v[1];
            }
        }
        return ans;
    }
}
