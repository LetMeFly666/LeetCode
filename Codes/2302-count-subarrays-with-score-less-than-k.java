/*
 * @Author: LetMeFly
 * @Date: 2025-04-29 23:46:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-30 10:41:19
 */
class Solution {
    public long countSubarrays(int[] nums, long k) {
        long ans = 0, cnt = 0;
        for (int l = 0, r = 0; r < nums.length; r++) {
            cnt += nums[r];
            while (cnt * (r - l + 1) >= k) {
                cnt -= nums[l++];
            }
            ans += (r - l + 1);
        }
        return ans;
    }
}