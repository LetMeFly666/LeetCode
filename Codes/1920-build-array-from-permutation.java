/*
 * @Author: LetMeFly
 * @Date: 2025-05-06 21:30:01
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-06 21:37:52
 */
class Solution {
    public int[] buildArray(int[] nums) {
        int[] ans = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            ans[i] = nums[nums[i]];
        }
        return ans;
    }
}