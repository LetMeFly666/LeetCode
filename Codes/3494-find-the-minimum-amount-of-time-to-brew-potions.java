/*
 * @Author: LetMeFly
 * @Date: 2025-10-09 22:52:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-09 23:34:16
 */
class Solution {
    public long minTime(int[] skill, int[] mana) {
        int n = skill.length;
        long[] times = new long[n];
        for (int m : mana) {
            long last = times[0] + skill[0] * m;
            for (int i = 1; i < n; i++) {
                last = Math.max(last, times[i]) + skill[i] * m;
            }
            times[n-1] = last;
            for (int i = n - 2; i >= 0; i--) {
                times[i] = times[i + 1] - skill[i + 1] * m;
            }
        }
        return times[n-1];
    }
}