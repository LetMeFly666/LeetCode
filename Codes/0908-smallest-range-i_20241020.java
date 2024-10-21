/*
 * @Author: LetMeFly
 * @Date: 2024-10-21 14:31:30
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-21 14:32:53
 */
class Solution {
    public int smallestRangeI(int[] nums, int k) {
        int M = nums[0], m = nums[0];
        for (int t : nums) {
            M = Math.max(M, t);
            m = Math.min(m, t);
        }
        return Math.max(0, M - m  - 2 * k);
    }
}