/*
 * @Author: LetMeFly
 * @Date: 2026-10-11 09:11:24
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-11 09:27:59
 */
class Solution {
    public int sumOfSquares(int[] nums) {
        int ans = 0;
        for (int i = 1, n = nums.length, root = (int)Math.sqrt(n); i <= root; i++) {
            if (n % i == 0) {
                ans += nums[i - 1] * nums[i - 1];
                if (i * i != n) {
                    ans += nums[n / i - 1] * nums[n / i - 1];
                }
            }
        }
        return ans;
    }
}
