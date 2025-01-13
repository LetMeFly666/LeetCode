/*
 * @Author: LetMeFly
 * @Date: 2025-01-13 22:35:06
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-13 22:36:41
 */
class Solution {
    public int waysToSplitArray(int[] nums) {
        long[] prefix = new long[nums.length];
        prefix[0] = nums[0];
        for (int i = 1; i < nums.length; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        int ans = 0;
        for (int i = 0; i < nums.length - 1; i++) {
            if (prefix[i] >= prefix[nums.length - 1] - prefix[i]) {
                ans++;
            }
        }
        return ans;
    }
}