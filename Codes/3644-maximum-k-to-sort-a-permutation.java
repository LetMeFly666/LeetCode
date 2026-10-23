/*
 * @Author: LetMeFly
 * @Date: 2026-10-23 20:28:52
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-23 20:34:40
 */
class Solution {
    public int sortPermutation(int[] nums) {
        if (nums[0] != 0) {
            return 0;
        }
        int ans = -1;
        for (int i = 0, n = nums.length; i < n; i++) {
            if (i != nums[i]) {
                ans &= i;
            }
        }
        return ans == -1 ? 0 : ans;
    }
}
