/*
 * @Author: LetMeFly
 * @Date: 2025-03-26 13:48:53
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-26 13:48:58
 */
class Solution {
    public int minimumSum(int n, int k) {
        int to = Math.min(n, k / 2);
        n -= to;
        return to * (to + 1) / 2 + n * (k + k + n - 1) / 2;
    }
}