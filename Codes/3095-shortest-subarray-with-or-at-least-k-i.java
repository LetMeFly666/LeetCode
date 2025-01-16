/*
 * @Author: LetMeFly
 * @Date: 2025-01-16 12:27:30
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-16 12:29:04
 */
class Solution {
    public int minimumSubarrayLength(int[] nums, int k) {
        int ans = 100;
        for (int l = 0; l < nums.length; l++) {
            int val = nums[l];
            for (int r = l; r < nums.length; r++) {
                val |= nums[r];
                if (val >= k) {
                    ans = Math.min(ans, r - l + 1);
                    break;
                }
            }
        }
        return ans == 100 ? -1 : ans;
    }
}