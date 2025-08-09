/*
 * @Author: LetMeFly
 * @Date: 2025-08-09 22:23:22
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-09 22:36:19
 */
class Solution {
    public boolean isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
}