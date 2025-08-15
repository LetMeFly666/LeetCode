/*
 * @Author: LetMeFly
 * @Date: 2025-08-15 18:29:00
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-15 23:56:02
 */
class Solution {
    public boolean isPowerOfFour(int n) {
        return n > 0 && (n & (n - 1) == 0) && n % 3 == 1;
    }
}