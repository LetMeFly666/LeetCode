/*
 * @Author: LetMeFly
 * @Date: 2025-05-04 14:26:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-04 16:15:28
 */
class Solution {
    public int numEquivDominoPairs(int[][] dominoes) {
        int[] times = new int[81];
        int ans = 0;
        for (int[] d : dominoes) {
            ans += times[d[0] < d[1] ? (d[0] - 1) * 9 + d[1] - 1 : (d[1] - 1) * 9 + d[0] - 1]++;
        }
        return ans;
    }
}