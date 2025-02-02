/*
 * @Author: LetMeFly
 * @Date: 2025-02-02 11:08:09
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-02 11:08:11
 */
class Solution {
    public int maxCount(int m, int n, int[][] ops) {
        for (int[] op : ops) {
            m = Math.min(m, op[0]);
            n = Math.min(n, op[1]);
        }
        return m * n;
    }
}