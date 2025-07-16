/*
 * @Author: LetMeFly
 * @Date: 2025-07-16 13:16:29
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-16 13:41:23
 */
class Solution {
    public int maximumLength(int[] nums) {
        int ans = 0;
        int odd = 0;
        boolean last = nums[0] % 2 == 0;
        for (int t : nums) {
            if (t % 2 == 0) {
                if (last) {
                    last = false;
                    ans++;
                }
            } else {
                odd++;
                if (!last) {
                    last = true;
                    ans++;
                }
            }
        }
        return Math.max(ans, Math.max(odd, nums.length - odd));
    }
}