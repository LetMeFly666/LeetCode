/*
 * @Author: LetMeFly
 * @Date: 2025-12-25 12:56:03
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-25 13:18:34
 */
import java.util.Arrays;

class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        Arrays.sort(happiness);
        long ans = 0;
        int n = happiness.length;
        for (int i = 0; i < k; i++) {
            if (happiness.get(n - i) <= i) {
                return ans;
            }
            ans += happiness.get(n - i) - i;
        }
        return ans;
    }
}