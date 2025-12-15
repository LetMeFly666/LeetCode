/*
 * @Author: LetMeFly
 * @Date: 2025-12-15 13:32:17
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-15 18:57:44
 */
class Solution {
    public long getDescentPeriods(int[] prices) {
        long ans = 0, cnt = 0;
        for (int last = 0, i = 0; i <= prices.length; i++) {
            if (i == prices.length || prices[i] != last - 1) {
                ans += cnt * (cnt + 1) / 2;
                cnt = 0;
            }
            cnt++;
            last = prices[i];
        }
        return ans;
    }
}