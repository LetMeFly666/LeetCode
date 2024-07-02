/*
 * @Author: LetMeFly
 * @Date: 2024-07-02 09:38:18
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-02 10:49:46
 */

class Solution {
    private boolean isPrime(int n) {
        if (n == 1) {
            return false;
        }
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    public int maximumPrimeDifference(int[] nums) {
        int m = 10000000, M = -1;
        for (int i = 0; i < nums.length; i++) {
            if (isPrime(nums[i])) {
                m = Math.min(m, i);
                M = Math.max(M, i);
            }
        }
        return M - m;
    }
}