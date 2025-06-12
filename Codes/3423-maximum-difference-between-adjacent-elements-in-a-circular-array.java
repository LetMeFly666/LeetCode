/*
 * @Author: LetMeFly
 * @Date: 2025-06-12 22:49:40
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-12 23:01:46
 */
class Solution {
    public int maxAdjacentDistance(int[] nums) {
        int ans = Math.abs(nums[0] - nums[nums.length - 1]);
        for (int i = 1; i < nums.length; i++) {
            ans = Math.max(ans, Math.abs(nums[i] - nums[i - 1]));
        }
        return ans;
    }
}