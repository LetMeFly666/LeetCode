/*
 * @Author: LetMeFly
 * @Date: 2026-10-11 09:11:24
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-11 09:25:32
 */
class Solution {
    public int sumOfSquares(int[] nums) {
        int ans = 0;
        for (int i = 1, n = nums.length, root = Math.sqrt(n); i <= root; i++) {
            if (nums[i] % i == 0) {
                ans += nums[i - 1] * nums[i - 1];
                if (i * i != root) {
                    ans += nums[root / i - 1] * nums[root / i - 1];
                }
            }
        }
        return ans;
    }
}
