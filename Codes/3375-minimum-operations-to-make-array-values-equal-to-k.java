/*
 * @Author: LetMeFly
 * @Date: 2025-04-09 22:12:36
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-09 22:15:42
 */
import java.util.Arrays;

class Solution {
    public int minOperations(int[] nums, int k) {
        Arrays.sort(nums);
        if (nums[0] < k) {
            return -1;
        }
        int ans = 0;
        for (int i = nums.length - 1; i > 0; i--) {
            if (nums[i] != nums[i - 1]) {
                ans++;
            }
        }
        if (nums[0] != k) {
            ans++;
        }
        return ans;
    }
}