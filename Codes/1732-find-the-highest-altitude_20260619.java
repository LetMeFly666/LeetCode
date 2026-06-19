/*
 * @Author: LetMeFly
 * @Date: 2026-06-19 10:15:51
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-06-19 10:18:18
 */
class Solution {
    public int largestAltitude(int[] gain) {
        int ans = 0, now = 0;
        for (int t : gain) {
            now += t;
            ans = Math.max(ans, now);
        }
        return ans;
    }
}
