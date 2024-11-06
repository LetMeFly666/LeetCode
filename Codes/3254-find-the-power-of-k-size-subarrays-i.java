/*
 * @Author: LetMeFly
 * @Date: 2024-11-06 17:14:08
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-06 17:17:37
 */
class Solution {
    public int[] resultsArray(int[] nums, int k) {
        int[] ans = new int[nums.length - k + 1];
        for (int i = 0; i + k <= nums.length; i++) {
            for (int j = i + 1; j < i + k; j++) {
                if (nums[j] != nums[j - 1] + 1) {
                    ans[i] = -1;
                    break;
                }
            }
            ans[i] = ans[i] == -1 ? -1 : nums[i + k - 1];
        }
        return ans;
    }
}