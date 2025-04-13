/*
 * @Author: LetMeFly
 * @Date: 2025-04-13 17:07:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-13 17:09:52
 */
class Solution {
    private final long mod = 1e9 + 7;

    private long pow(long a, long b) {
        long ans = 1;
        while (b > 0) {
            if (b & 1 == 1) {
                ans = ans * a % mod;
            }
            a = a * a % mod;
            b >>= 1;
        }
        return ans;
    }

    public int countGoodNumbers(long n) {
        return pow(5, (n + 1) / 2) * pow(4, n / 2) % mod;
    }
}