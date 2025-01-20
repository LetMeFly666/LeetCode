/*
 * @Author: LetMeFly
 * @Date: 2025-01-20 13:33:12
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-20 13:33:16
 */
class Solution {
    public int findClosestNumber(int[] nums) {
        int ans = nums[0];
        for (int t : nums) {
            if (Math.abs(t) < Math.abs(ans) || Math.abs(t) == Math.abs(ans) && ans < 0) {
                ans = t;
            }
        }
        return ans;
    }
}