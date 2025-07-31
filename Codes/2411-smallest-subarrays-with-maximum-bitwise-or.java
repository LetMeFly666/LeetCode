/*
 * @Author: LetMeFly
 * @Date: 2025-07-29 23:42:57
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-31 10:43:36
 */
class Solution {
    public int[] smallestSubarrays(int[] nums) {
        int[] ans = new int[nums.length];
        int[] lastPos = new int[31];
        for (int i = nums.length - 1; i >= 0; i--) {
            int last = i;
            for (int j = 0; j < 31; j++) {
                if (nums[i] >> j & 1 == 1) {
                    lastPos[j] = i;
                } else {
                    last = Math.max(last, lastPos[j]);
                }
            }
            ans[i] = Math.max(ans[i], last - i + 1);
        }
        return ans;
    }
}