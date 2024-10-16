/*
* @Author: LetMeFly
* @Date: 2024-10-16 23:09:10
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-16 23:10:34
*/
import java.util.Arrays;

class Solution {
    public double minimumAverage(int[] nums) {
        Arrays.sort(nums);
        int ans = 1000;
        for (int i = 0; i < nums.length / 2; i++) {
            ans = Math.min(ans, nums[i] + nums[nums.length - i - 1]);
        }
        return 1. * ans / 2;
    }
}