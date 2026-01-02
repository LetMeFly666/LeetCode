/*
 * @Author: LetMeFly
 * @Date: 2026-01-02 17:44:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-02 17:44:51
 */
class Solution {
    public int repeatedNTimes(int[] nums) {
        for (int i = 2; i < nums.length; i++) {
            if (nums[i] == nums[i-1] || nums[i] == nums[i-2]) {
                return nums[i];
            }
        }
        return nums[0];
    }
}