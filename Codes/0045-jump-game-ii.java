/*
 * @Author: LetMeFly
 * @Date: 2025-01-27 07:55:47
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-27 07:56:59
 */
class Solution {
    public int jump(int[] nums) {
        int ans = 0, nowMax = 0, nextMax = 0;
        for (int i = 0; i < nums.length - 1; i++) {
            nextMax = Math.max(nextMax, i + nums[i]);
            if (i == nowMax) {
                nowMax = nextMax;
                ans++;
            }
        }
        return ans;
    }
}