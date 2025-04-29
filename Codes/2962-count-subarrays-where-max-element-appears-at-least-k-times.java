/*
 * @Author: LetMeFly
 * @Date: 2025-04-29 13:19:49
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-29 21:23:01
 */
class Solution {
    public long countSubarrays(int[] nums, int k) {
        int mx = nums[0];
        for (int t : nums) {
            mx = Math.max(mx, t);
        }
        long ans = 0;
        for (int l = 0, cnt = 0, r = 0; r < nums.length; r++) {
            if (nums[r] == mx) {
                cnt++;
            }
            while (cnt == k) {
                if (nums[l++] == mx) {
                    cnt--;
                }
            }
            ans += l;
        }
        return ans;
    }
}