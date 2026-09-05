/*
 * @Author: LetMeFly
 * @Date: 2026-09-05 08:24:28
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-05 08:49:55
 */
class Solution {
    public int firstStableIndex(int[] nums, int k) {
        int n = nums.length;
        int[] mini = new int[n];
        mini[n-1] = nums[n-1];
        for (int i = n - 2; i >= 0; i--) {
            mini[i] = Math.min(nums[i], mini[i + 1]);
        }
        for (int i = 0, M = 0; i < n; i++) {
            M = Math.max(M, nums[i]);
            if (M - mini[i] <= k) {
                return i;
            }
        }
        return -1;
    }
}
