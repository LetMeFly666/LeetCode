/*
 * @Author: LetMeFly
 * @Date: 2025-05-19 13:22:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-19 13:32:46
 */
import java.util.Arrays;

class Solution {
    public String triangleType(int[] nums) {
        Arrays.sort(nums);
        if (nums[0] + nums[1] <= nums[2]) {
            return "none";
        }
        if (nums[0] == nums[1] && nums[1] == nums[2]) {
            return "equilateral";
        }
        if (nums[0] == nums[1] || nums[1] == nums[2]) {
            return "isosceles";
        }
        return "scalene";
    }
}