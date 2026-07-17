/*
 * @Author: LetMeFly
 * @Date: 2026-07-18 07:00:55
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-18 07:06:24
 */
class Solution {
    public int findGCD(int[] nums) {
        int m = nums[0], M = m;
        for (int t : nums) {
            m = Math.min(m, t);
            M = Math.max(M, t);
        }
        return gcd(M, m);
    }

    private int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
}
