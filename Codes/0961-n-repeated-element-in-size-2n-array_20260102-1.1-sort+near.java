/*
 * @Author: LetMeFly
 * @Date: 2026-01-02 12:47:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-02 17:41:05
 */
import java.util.Arrays;

class Solution {
    public int repeatedNTimes(int[] nums) {
        Arrays.sort(nums);
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == nums[i-1]) {
                return nums[i];
            }
        }
        return -1;
    }
}