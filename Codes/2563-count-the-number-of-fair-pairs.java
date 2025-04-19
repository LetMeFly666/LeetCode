/*
 * @Author: LetMeFly
 * @Date: 2025-04-19 16:24:08
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-19 16:37:36
 */
import java.util.Arrays;

class Solution {
    private int search(int[] nums, int x, int l) {  // search [l, len(nums)) 范围内第一个大于等于x的下标
        int r = nums.length;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
    public long countFairPairs(int[] nums, int lower, int upper) {
        Arrays.sort(nums);
        long ans = 0;
        for (int i = 0; i < nums.length; i++) {
            ans += search(nums, upper - nums[i] + 1, i + 1) - search(nums, lower - nums[i], i + 1);
        }
        return ans;
    }
}