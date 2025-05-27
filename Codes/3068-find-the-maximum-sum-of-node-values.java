/*
 * @Author: LetMeFly
 * @Date: 2025-05-27 23:28:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-27 23:42:20
 */
class Solution {
    public long maximumValueSum(int[] nums, int k, int[][] edges) {
        long odd = 0, even = -1000000000000000;
        for (int t : nums) {
            long newO = Math.max(odd + t, even + (t ^ k));
            long newE = Math.max(even + t, odd + (t ^ k));
        }
        return even;
    }
}