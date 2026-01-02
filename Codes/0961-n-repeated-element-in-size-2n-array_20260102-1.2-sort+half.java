/*
 * @Author: LetMeFly
 * @Date: 2026-01-02 17:43:17
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-02 17:43:23
 */
import java.util.Arrays;

class Solution {
    public int repeatedNTimes(int[] nums) {
        Arrays.sort(nums);
        int mid = nums.length / 2;
        return nums[mid] == nums[mid + 1] ? nums[mid] : nums[mid - 1];
    }
}