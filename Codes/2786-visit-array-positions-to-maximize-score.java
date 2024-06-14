/*
 * @Author: LetMeFly
 * @Date: 2024-06-14 19:04:20
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-14 19:06:28
 */
class Solution {
    public long maxScore(int[] nums, int x) {
        long odd = nums[0] % 2 != 0 ? 0 : -x, even = nums[0] % 2 != 0 ? -x : 0;
        for (int t : nums) {
            if (t % 2 != 0) {
                odd = Math.max(odd + t, even + t - x);
            }
            else {
                even = Math.max(odd + t - x, even + t);
            }
        }
        return Math.max(odd, even);
    }
}