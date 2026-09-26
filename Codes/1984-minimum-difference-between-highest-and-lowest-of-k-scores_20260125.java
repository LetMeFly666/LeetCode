/*
 * @Author: LetMeFly
 * @Date: 2026-01-25 10:32:52
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-25 10:40:30
 */
import java.util.Arrays;

class Solution {
    public int minimumDifference(int[] nums, int k) {
        int ans = 100000;
        Arrays.sort(nums);
        for (int i = 0; i + k - 1 < nums.length; i++) {
            ans = Math.min(ans, nums[i + k - 1] - nums[i]);
        }
        return ans;
    }
}