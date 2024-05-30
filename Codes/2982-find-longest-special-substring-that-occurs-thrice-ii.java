/*
 * @Author: LetMeFly
 * @Date: 2024-05-30 16:59:10
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-05-30 17:15:30
 */
class Solution {
    private void add(int[] times, int n) {
        if (n > times[2]) {
            times[2] = n;
            if (times[2] > times[1]) {
                times[2] = times[2] ^ times[1] ^ (times[1] = times[2]);
                if (times[1] > times[0]) {
                    times[1] = times[1] ^ times[0] ^ (times[0] = times[1]);
                }
            }
        }
    }

    private int getTimes(int[] times) {
        return Math.max(
            Math.min(times[0], Math.min(times[1], times[2])),
            Math.max(
                Math.min(times[0] - 1, times[1]),
                times[0] - 2
            )
        );
    }

    public int maximumLength(String s) {
        int[][] times = new int[26][3];
        int from = 0;
        for (int i = 1; i <= s.length(); i++) {
            if (i == s.length() || s.charAt(i) != s.charAt(i - 1)) {
                add(times[s.charAt(i - 1) - 'a'], i - from);
                from = i;
            }
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            ans = Math.max(ans, getTimes(times[i]));
        }
        return ans != 0 ? ans : -1;
    }
}