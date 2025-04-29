/*
 * @Author: LetMeFly
 * @Date: 2025-04-27 23:49:11
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-27 23:50:25
 */
class Solution {
    public int countSubarrays(int[] nums) {
        int ans = 0;
        for (int i = 2; i < nums.length; i++) {
            if ((nums[i - 2] + nums[i]) * 2 == nums[i - 1]) {
                ans++;
            }
        }
        return ans;
    }
}