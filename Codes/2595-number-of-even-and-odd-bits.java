/*
 * @Author: LetMeFly
 * @Date: 2025-02-20 11:06:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-20 11:10:57
 */
class Solution {
    public int[] evenOddBit(int n) {
        int[] ans = new int[2];
        int index = 0;
        while (n > 0) {
            ans[index] += n & 1;
            index ^= 1;
            n >>= 1;
        }
        return ans;
    }
}