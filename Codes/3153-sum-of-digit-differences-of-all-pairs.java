/*
 * @Author: LetMeFly
 * @Date: 2024-08-30 22:00:27
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-08-30 22:08:25
 */
class Solution {
    public long sumDigitDifferences(int[] nums) {
        long ans = 0;
        while (nums[0] > 0) {
            long[] times = new long[10];
            for (int i = 0; i < nums.length; i++) {
                times[nums[i] % 10]++;
                nums[i] /= 10;
            }
            for (int i = 0; i < 10; i++) {
                ans += times[i] * (nums.length - times[i]);
            }
        }
        return ans / 2;
    }
}