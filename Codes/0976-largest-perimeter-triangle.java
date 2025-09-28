/*
 * @Author: LetMeFly
 * @Date: 2025-09-28 13:21:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-28 13:27:11
 */
import java.util.Arrays;

class Solution {
    public int largestPerimeter(int[] nums) {
        Arrays.sort(nums);
        for (int i = nums.length - 3; i >= 0; i--) {
            if (nums[i] + nums[i + 1] > nums[i + 2]) {
                return nums[i] + nums[i + 1] + nums[i + 2];
            }
        }
        return 0;
    }
}