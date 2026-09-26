/*
 * @Author: LetMeFly
 * @Date: 2026-04-13 21:39:33
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-04-13 21:44:45
 */
class Solution {
    public int getMinDistance(int[] nums, int target, int start) {
        int ans = nums.length;
        for (int i = 0, n = nums.length; i < n; i++) {
            if (nums[i] == target) {
                ans = Math.min(ans, Math.abs(i - start));
            }
        }
        return ans;
    }
}
