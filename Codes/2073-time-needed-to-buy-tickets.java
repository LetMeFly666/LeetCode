/*
 * @Author: LetMeFly
 * @Date: 2024-10-03 13:51:39
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-03 13:56:26
 */
class Solution {
    public int timeRequiredToBuy(int[] tickets, int k) {
        int ans = 0;
        for (int i = 0; i < tickets.length; i++) {
            if (i <= k) {
                ans += Math.min(tickets[i], tickets[k]);
            } else {
                ans += Math.min(tickets[i], tickets[k] - 1);
            }
        }
        return ans;
    }
}