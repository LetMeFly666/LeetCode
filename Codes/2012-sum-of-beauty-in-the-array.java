/*
 * @Author: LetMeFly
 * @Date: 2025-03-11 14:07:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-11 14:10:09
 */
class Solution {
    public int sumOfBeauties(int[] nums) {
        int[] mx = new int[nums.length];
        int[] mn = new int[nums.length];
        int now = 0;
        for (int i = 0; i < nums.length; i++) {
            mx[i] = now = Math.max(now, nums[i]);
        }
        for (int i = nums.length - 1; i >= 0; i--) {
            mn[i] = now = Math.min(now, nums[i]);
        }
        int ans = 0;
        for (int i = 1; i < nums.length - 1; i++) {
            if (mx[i - 1] < nums[i] && nums[i] < mn[i + 1]) {
                ans += 2;
            } else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) {
                ans++;
            }
        }
        return ans;
    }
}