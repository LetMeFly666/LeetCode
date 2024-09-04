/*
 * @Author: LetMeFly
 * @Date: 2024-09-01 14:56:14
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-09-01 14:59:58
 */
class Solution {
    public int busyStudent(int[] startTime, int[] endTime, int queryTime) {
        int ans = 0;
        for (int i = 0; i < startTime.length; i++) {
            if (startTime[i] <= queryTime && queryTime <= endTime[i]) {
                ans++;
            }
        }
        return ans;
    }
}