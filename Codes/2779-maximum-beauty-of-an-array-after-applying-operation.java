/*
 * @Author: LetMeFly
 * @Date: 2024-06-15 19:09:58
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-15 19:12:52
 */
import java.util.Arrays;
import java.lang.Math;

class Solution {
    public int maximumBeauty(int[] nums, int k) {
        int ans = 0;
        Arrays.sort(nums);
        k *= 2;
        for (int l = 0, r = 0; r < nums.length; r++) {
            while (nums[r] - nums[l] > k) {
                l++;
            }
            ans = Math.max(ans, r - l + 1);
        }
        return ans;
    }
}