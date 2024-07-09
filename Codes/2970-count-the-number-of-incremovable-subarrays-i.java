/*
 * @Author: LetMeFly
 * @Date: 2024-07-10 00:21:39
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-10 00:23:41
 */
class Solution {
    private boolean isOk(int[] nums, int l, int r) {
        int last = 0;
        for (int i = 0; i < nums.length; i++) {
            if (l <= i && i <= r) {
                continue;
            }
            if (nums[i] <= last) {
                return false;
            }
            last = nums[i];
        }
        return true;
    }

    public int incremovableSubarrayCount(int[] nums) {
        int ans = 0;
        for (int l = 0; l < nums.length; l++) {
            for (int r = l; r < nums.length; r++) {
                ans += isOk(nums, l, r) ? 1 : 0;
            }
        }
        return ans;
    }
}