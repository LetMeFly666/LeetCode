/*
 * @Author: LetMeFly
 * @Date: 2025-09-26 22:40:03
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-26 22:51:26
 */
import java.util.Arrays;

class Solution {
    public int triangleNumber(int[] nums) {
        Arrays.sort(nums);
        int ans = 0;
        for (int i = nums.length - 1; i >= 0; i--) {
            for (int l = 0, r = i - 1; l < r;) {
                if (nums[l] + nums[r] > nums[i]) {
                    ans += r - 1;
                    r--;
                } else {
                    l++;
                }
            }
        }
        return ans;
    }
}