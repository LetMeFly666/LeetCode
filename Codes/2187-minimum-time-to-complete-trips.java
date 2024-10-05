/*
 * @Author: LetMeFly
 * @Date: 2024-10-05 18:20:14
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-05 18:22:28
 */
class Solution {
    private boolean check(int[] times, long totalTrips, long timeCnt) {
        for (int t : times) {
            totalTrips -= timeCnt / t;
        }
        return totalTrips <= 0;
    }
    public long minimumTime(int[] times, int totalTrips) {
        long l = 1, r = (long)1e14 + 1;
        while (l < r) {
            long mid = (l + r) >> 1;
            if (check(times, totalTrips, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
}