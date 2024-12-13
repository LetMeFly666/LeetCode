/*
 * @Author: LetMeFly
 * @Date: 2024-12-13 09:37:28
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-13 09:40:00
 */
class Solution {
    public int[] getFinalState(int[] nums, int k, int multiplier) {
        for (int round = 0; round < k; round++) {
            int m = nums[0], loc = 0;
            for (int i = 1; i < nums.length; i++) {
                if (nums[i] < m) {
                    m = nums[i];
                    loc = i;
                }
            }
            nums[loc] *= multiplier;
        }
        return nums;
    }
}