/*
 * @Author: LetMeFly
 * @Date: 2025-04-06 16:31:30
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-06 16:33:16
 */
class Solution {
    public int subsetXORSum(int[] nums) {
        int ans = 0;
        for (int i = 0; i < 1 << nums.length; i++) {
            int thisCnt = 0;
            for (int j = 0; j < nums.length; j++) {
                if ((i >> j & 1) == 1) {
                    thisCnt ^= nums[j];
                }
            }
            ans += thisCnt;
        }
        return ans;
    }
}