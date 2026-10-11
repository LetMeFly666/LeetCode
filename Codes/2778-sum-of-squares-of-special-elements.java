/*
 * @Author: LetMeFly
 * @Date: 2026-10-11 09:02:48
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-11 09:06:29
 */
class Solution {
    public int sumOfSquares(int[] nums) {
        int ans = 0;
        for (int i = 0, n = nums.length; i < n; i++) {
            if (n % (i + 1) == 0) {
                ans += nums[i] * nums[i];
            }
        }
        return ans;
    }
}
