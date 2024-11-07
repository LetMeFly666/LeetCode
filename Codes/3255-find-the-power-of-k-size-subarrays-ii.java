/*
 * @Author: LetMeFly
 * @Date: 2024-11-07 12:26:49
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-07 12:29:31
 */
class Solution {
    public int[] resultsArray(int[] nums, int k) {
        int[] ans = new int[nums.length - k + 1];
        int notCoutinue = 0;
        for (int i = 1; i < k; i++) {
            if (nums[i] != nums[i - 1] + 1) {
                notCoutinue++;
            }
        }
        ans[0] = notCoutinue > 0 ? -1 : nums[k - 1];
        for (int i = 1; i + k <= nums.length; i++) {
            if (nums[i] != nums[i - 1] + 1) {
                notCoutinue--;
            }
            if (nums[i + k - 1] != nums[i + k - 2] + 1) {
                notCoutinue++;
            }
            ans[i] = notCoutinue > 0 ? -1 : nums[i + k - 1];
        }
        return ans;
    }
}