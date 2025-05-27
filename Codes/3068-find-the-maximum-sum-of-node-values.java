/*
 * @Author: LetMeFly
 * @Date: 2025-05-27 23:28:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-27 23:45:06
 */
class Solution {
    public long maximumValueSum(int[] nums, int k, int[][] edges) {
        long even = 0, odd = -1000000000000000L;  // 记得带“L”
        for (int t : nums) {
            long newO = Math.max(odd + t, even + (t ^ k));
            long newE = Math.max(even + t, odd + (t ^ k));
            odd = newO;
            even = newE;
        }
        return even;
    }
}