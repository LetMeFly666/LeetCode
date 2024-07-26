/*
 * @Author: LetMeFly
 * @Date: 2024-07-26 15:22:32
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-26 15:24:53
 * @Description: AC,100.00%,97.03% https://leetcode.cn/problems/find-the-value-of-the-partition/submissions/549897673/
 */
import java.util.Arrays;

class Solution {
    public int findValueOfPartition(int[] nums) {
        Arrays.sort(nums);
        int ans = 1000000000;
        for (int i = 1; i < nums.length; i++) {
            ans = Math.min(ans, Math.abs(nums[i] - nums[i - 1]));
        }
        return ans;
    }
}