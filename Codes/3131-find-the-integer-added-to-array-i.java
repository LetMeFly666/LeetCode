/*
 * @Author: LetMeFly
 * @Date: 2024-08-08 22:16:45
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-08-08 22:17:49
 */
class Solution {
    private int min(int[] nums) {
        int ans = nums[0];
        for (int i = 1; i < nums.length; i++) {
            ans = Math.min(ans, nums[i]);
        }
        return ans;
    }

    public int addedInteger(int[] nums1, int[] nums2) {
        return min(nums2) - min(nums1);
    }
}