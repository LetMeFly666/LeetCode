/*
 * @Author: LetMeFly
 * @Date: 2026-01-24 09:29:52
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-24 09:39:41
 */
import java.util.Arrays;

class Solution {
    public int minPairSum(int[] nums) {
        Arrays.sort(nums);
        int ans = 0;
        for (int i = 0; i < nums.length / 2; i++) {
            ans = Math.max(ans, nums[i] + nums[nums.length - i - 1]);
        }
        return ans;
    }
}