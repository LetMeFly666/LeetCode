/*
 * @Author: LetMeFly
 * @Date: 2024-09-12 21:21:25
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-09-12 21:35:29
 */
import java.util.Arrays;

class Solution {
    public int maxNumOfMarkedIndices(int[] nums) {
        Arrays.sort(nums);
        int ans = 0;
        for (int i = 0, r = (nums.length + 1) / 2; r < nums.length; r++) {
            if (nums[i] * 2 <= nums[r]) {
                ans += 2;
                i++;
            }
        }
        return ans;
    }
}