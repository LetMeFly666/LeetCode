/*
 * @Author: LetMeFly
 * @Date: 2025-03-18 23:50:23
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-18 23:55:24
 */
class Solution {
    private boolean isPrime(int n) {
        if (n < 2) {
            return false;
        }
        int k = (int)Math.sqrt(n);
        for (int i = 2; i <= k; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    public int diagonalPrime(int[][] nums) {
        int ans = 0;
        for (int i = 0; i < nums.length; i++) {
            if (isPrime(nums[i][i])) {
                ans = Math.max(ans, nums[i][i]);
            }
            if (isPrime(nums[i][nums.length - i - 1])) {
                ans = Math.max(ans, nums[i][nums.length - i - 1]);
            }
        }
        return ans;
    }
}