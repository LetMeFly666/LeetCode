/*
 * @Author: LetMeFly
 * @Date: 2025-04-13 13:00:58
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-13 13:37:04
 * @Description: AC,70.30%,86.73%
 */
import java.util.Arrays;

class Solution {
    private int n, nonFixed, limit;
    private String start, finish, suffix;
    private long[] cache;

    private long dfs(int i, boolean limitLow, boolean limitHigh) {
        if (i == n) {
            return 1;
        }
        if (!limitLow && !limitHigh && cache[i] != -1) {
            return cache[i];
        }
        int low = limitLow ? start.charAt(i) - '0' : 0;
        int high = limitHigh ? finish.charAt(i) - '0' : 9;
        long ans = 0;
        if (i < nonFixed) {
            for (int d = low; d <= Math.min(limit, high); d++) {
                ans += dfs(i + 1, limitLow && d == low, limitHigh && d == high);
            }
        } else {
            int x = suffix.charAt(i - nonFixed) - '0';
            if (low <= x && x <= high) {
                ans = dfs(i + 1, limitLow && x == low, limitHigh && x == high);
            }
        }
        if (!limitLow && !limitHigh) {
            cache[i] = ans;
        }
        return ans;
    }
    
    public long numberOfPowerfulInt(long start, long finish, int limit, String s) {
        this.finish = String.valueOf(finish);
        n = this.finish.length();
        this.start = String.valueOf(start);
        this.start = "0".repeat(n - this.start.length()) + this.start;
        this.limit = limit;
        nonFixed = n - s.length();
        cache = new long[n];
        Arrays.fill(cache, -1);
        suffix = s;
        return dfs(0, true, true);
    }
}