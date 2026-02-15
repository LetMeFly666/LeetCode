/*
 * @Author: LetMeFly
 * @Date: 2026-02-15 18:09:49
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-15 18:16:30
 */
class Solution {
    public int[] constructTransformedArray(int[] nums) {
        int[] ans = new int[nums.length];
        for (int i = 0, n = nums.length; i < n; i++) {
            ans[i] = nums[((nums[i] + i) % n + n) % n];
        }
        return ans;
    }
}