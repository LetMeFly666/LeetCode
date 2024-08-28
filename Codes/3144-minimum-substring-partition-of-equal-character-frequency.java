/*
 * @Author: LetMeFly
 * @Date: 2024-08-28 23:13:28
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-08-28 23:21:02
 */
import java.util.Map;
import java.util.HashMap;
import java.util.Arrays;

class Solution {
    public int minimumSubstringsInPartition(String s) {
        int[] dp = new int[s.length() + 1];
        Arrays.fill(dp, 100000);
        dp[0] = 0;
        Map<Character, Integer> ma = new HashMap<Character, Integer>();
        for (int i = 0; i < s.length(); i++) {
            ma.clear();
            int types = 0, maxTimes = 0;
            for (int j = i; j >= 0; j--) {
                int originalTimes = ma.getOrDefault(s.charAt(j), 0);
                ma.put(s.charAt(j), originalTimes + 1);
                maxTimes = Math.max(maxTimes, originalTimes + 1);
                if (originalTimes == 0) {
                    types++;
                }
                if (maxTimes * types == i - j + 1) {
                    dp[i + 1] = Math.min(dp[i + 1], dp[j] + 1);
                }
            }
        }
        return dp[s.length()];
    }
}