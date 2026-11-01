/*
 * @Author: LetMeFly
 * @Date: 2026-11-01 10:57:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-11-01 11:01:07
 */
class Solution {
    public int minMoves(int[] nums) {
        int m = nums[0];
        for (int t : nums) {
            m = Math.min(m, t);
        }
        int ans = 0;
        for (int t : nums) {
            ans += t - m;
        }
        return ans;
    }
}
