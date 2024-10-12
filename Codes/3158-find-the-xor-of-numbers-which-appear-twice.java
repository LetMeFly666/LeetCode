/*
 * @Author: LetMeFly
 * @Date: 2024-10-12 14:31:03
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-12 14:32:15
 */
class Solution {
    public int duplicateNumbersXOR(int[] nums) {
        long ma = 0;
        int ans = 0;
        for (int t : nums) {
            if ((ma >> t & 1) > 0) {
                ans ^= t;
            } else {
                ma ^= (long)(1) << t;
            }
        }
        return ans;
    }
}