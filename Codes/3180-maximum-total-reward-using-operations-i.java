/*
 * @Author: LetMeFly
 * @Date: 2024-10-28 21:27:54
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-28 21:31:47
 */
import java.util.Arrays;

class Solution {
    public int maxTotalReward(int[] rewardValues) {
        Arrays.sort(rewardValues);
        boolean[] dp = new boolean[2 * rewardValues[rewardValues.length - 1]];
        dp[0] = true;
        for (int x : rewardValues) {
            for (int i = x; i < 2 * x; i++) {
                dp[i] |= dp[i - x];
            }
        }
        int ans = dp.length - 1;
        while (!dp[ans]) {
            ans--;
        }
        return ans;
    }
}