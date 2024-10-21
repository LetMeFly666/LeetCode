/*
 * @Author: LetMeFly
 * @Date: 2024-10-21 23:06:25
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-21 23:10:53
 */
import java.util.Arrays;

class Solution {
    public int smallestRangeII(int[] nums, int k) {
        Arrays.sort(nums);
        int ans = nums[nums.length - 1] - nums[0];
        for (int i = 0; i < nums.length - 1; i++) {
            ans = Math.min(ans, Math.max(nums[i] + k, nums[nums.length - 1] - k) - Math.min(nums[i + 1] - k, nums[0] + k));
        }
        return ans;
    }
}