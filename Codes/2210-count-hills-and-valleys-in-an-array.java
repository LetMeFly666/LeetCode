/*
 * @Author: LetMeFly
 * @Date: 2025-07-28 21:39:52
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-28 22:25:46
 */
class Solution {
    public int countHillValley(int[] nums) {
        int last = nums[0];
        int ans = 0;
        for (int i = 1; i < nums.length - 1; i++) {
            if (nums[i] > last && nums[i] > nums[i + 1] || nums[i] < last && nums[i] < nums[i + 1]) {
                ans++;
            }
            if (nums[i] != nums[i + 1]) {
                last = nums[i];
            }
        }
        return ans;
    }
}