/*
 * @Author: LetMeFly
 * @Date: 2025-04-23 13:23:09
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-23 13:24:57
 */
import java.util.Map;
import java.util.HashMap;

class Solution {
    public int countLargestGroup(int n) {
        Map<Integer, Integer> times = new HashMap<>();
        int maxTimes = 0;
        for (int i = 1; i <= n; i++) {
            int cnt = 0, temp = i;
            while (temp > 0) {
                cnt += temp % 10;
                temp /= 10;
            }
            maxTimes = Math.max(maxTimes, times.merge(cnt, 1, Integer::sum));
        }
        int ans = 0;
        for (Map.Entry<Integer, Integer> pair : times.entrySet()) {
            if (pair.getValue() == maxTimes) {
                ans++;
            }
        }
        return ans;
    }
}