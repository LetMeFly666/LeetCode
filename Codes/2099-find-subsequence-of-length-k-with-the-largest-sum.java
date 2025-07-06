/*
 * @Author: LetMeFly
 * @Date: 2025-07-03 21:31:48
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-06 21:50:33
 */
import java.util.Arrays;

class Solution {
    public int[] maxSubsequence(int[] nums, int k) {
        int[] idx = new int[len(nums)];
        for (int i = 0; i < len(nums); i++) {
            idx[i] = i;
        }
        Arrays.sort(idx, (i, j) -> nums[j] - nums[i]);
        int[] ans = new int[k];
        Arrays.sort(idx);
        for (int i = 0; i < k; i++) {
            ans[i] = nums[idx[i]];
        }
        return ans;
    }
}