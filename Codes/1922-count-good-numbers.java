/*
 * @Author: LetMeFly
 * @Date: 2025-04-13 17:07:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-14 00:07:21
 * @Description: AC,100.00%,87.23%
 */
class Solution {
    private final long mod = 1000000007;

    private long pow(long a, long b) {
        long ans = 1;
        while (b > 0) {
            if ((b & 1) == 1) {
                ans = ans * a % mod;
            }
            a = a * a % mod;
            b >>= 1;
        }
        return ans;
    }

    public int countGoodNumbers(long n) {
        return (int)(pow(5, (n + 1) / 2) * pow(4, n / 2) % mod);
    }
}