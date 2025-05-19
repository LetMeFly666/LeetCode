/*
 * @Author: LetMeFly
 * @Date: 2025-05-19 13:22:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-19 13:30:57
 */
import java.util.Arrays;

class Solution {
    public String triangleType(int[] nums) {
        Arrays.sort(nums);
        if (nums[0] + nums[1] <= nums[2]) {
            return new String("none");
        }
        return "none";  // test if ok
    }
}