/*
 * @Author: LetMeFly
 * @Date: 2025-07-03 21:31:48
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-06 22:03:44
 */
import java.util.Arrays;

class Solution {
    public int[] maxSubsequence(int[] nums, int k) {
        Integer[] idx = new Integer[nums.length];
        for (int i = 0; i < nums.length; i++) {
            idx[i] = i;
        }
        Arrays.sort(idx, (i, j) -> nums[j] - nums[i]);
        int[] ans = new int[k];
        for (int i = 0; i < k; i++) {
            ans[i] = idx[i];
        }
        Arrays.sort(ans);
        for (int i = 0; i < k; i++) {
            ans[i] = nums[ans[i]];
        }
        return ans;
    }
}