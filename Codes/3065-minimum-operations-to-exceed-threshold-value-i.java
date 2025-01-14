/*
 * @Author: LetMeFly
 * @Date: 2025-01-14 12:31:59
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-14 12:32:19
 */
class Solution {
    public int minOperations(int[] nums, int k) {
        int ans = 0;
        for (int t : nums) {
            if (t < k) {
                ans++;
            }
        }
        return ans;
    }
}