/*
 * @Author: LetMeFly
 * @Date: 2025-07-13 21:44:10
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-13 22:15:49
 */
class Solution {
    public int maxFreeTime(int eventTime, int k, int[] startTime, int[] endTime) {
        int cnt = 0;
        for (int i = 0; i < k; i++) {
            cnt += endTime[i] - startTime[i];
        }
        int n = startTime.length;
        int ans = 0;
        for (int i = k; i <= n; i++) {
            int l = (i == k ? 0 : endTime[i - k - 1]) + cnt;
            int r = i == n ? eventTime : startTime[i];
            ans = Math.max(ans, r - l);
            if (i == n) {
                break;
            }
            cnt += endTime[i] - startTime[i];
            cnt -= endTime[i] - startTime[i];
        }
        return ans;
    }
}