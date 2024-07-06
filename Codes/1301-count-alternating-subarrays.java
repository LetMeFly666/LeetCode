/*
 * @Author: LetMeFly
 * @Date: 2024-07-06 10:45:47
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-06 10:46:46
 */
class Solution {
    public long countAlternatingSubarrays(int[] nums) {
        long ans = 0;
        for (int from = 0, to = 1; to <= nums.length; to++) {
            if (to == nums.length || nums[to] == nums[to - 1]) {
                long length = to - from;
                ans += (1 + length) * length / 2;
                from = to;
            }
        }
        return ans;
    }
}