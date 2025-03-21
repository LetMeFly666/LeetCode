/*
 * @Author: LetMeFly
 * @Date: 2025-03-21 15:32:20
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-21 15:34:12
 */
class Solution {
    public long maximumOr(int[] nums, int k) {
        int allOr = 0, all1 = 0;
        for (int t : nums) {
            all1 |= t & allOr;
            allOr |= t;
        }
        long ans = 0;
        for (int t : nums) {
            ans = Math.max(ans, allOr ^ t | all1 | (long)t << k);
        }
        return ans;
    }
}