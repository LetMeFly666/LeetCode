/*
 * @Author: LetMeFly
 * @Date: 2025-04-17 20:17:48
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-17 20:18:12
 */
class Solution {
    public int countPairs(int[] nums, int k) {
        int ans = 0;
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] == nums[j] && i * j % k == 0) {
                    ans++;
                }
            }
        }
        return ans;
    }
}