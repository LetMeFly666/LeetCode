/*
 * @Author: LetMeFly
 * @Date: 2024-09-03 18:24:08
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-09-03 18:36:42
 */
class Solution {
    public long maxStrength(int[] nums) {
        long m = nums[0], M = nums[0];
        for (int i = 1; i < nums.length; i++) {
            long newm = Math.min(m, Math.min((long)(nums[i]), Math.min(m * nums[i], M * nums[i])));
            long newM = Math.max(M, Math.max((long)(nums[i]), Math.max(m * nums[i], M * nums[i])));
            m = newm;
            M = newM;
        }
        return M;
    }
}