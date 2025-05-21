/*
 * @Author: LetMeFly
 * @Date: 2025-05-21 23:06:35
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-21 23:20:50
 */
class Solution {
    public boolean isZeroArray(int[] nums, int[][] queries) {
        int[] diff = new int[nums.length + 1];
        for (int[] q : queries) {
            diff[q[0]]++;
            diff[q[1] + 1]--;
        }
        int cnt = 0;
        for (int i = 0; i < nums.length; i++) {
            cnt += diff[i];
            if (nums[i] > cnt) {
                return false;
            }
        }
        return true;
    }
}