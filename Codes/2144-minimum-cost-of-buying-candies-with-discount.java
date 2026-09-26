/*
 * @Author: LetMeFly
 * @Date: 2026-06-01 22:06:51
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-06-01 22:11:38
 */
import java.util.Arrays;

class Solution {
    public int minimumCost(int[] cost) {
        int ans = 0;
        Arrays.sort(cost);
        for (int i = cost.length - 1; i >= 0; i -= 3) {
            ans += cost[i];
            if (i > 0) {
                ans += cost[i - 1];
            }
        }
        return ans;
    }
}
