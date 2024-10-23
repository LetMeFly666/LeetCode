/*
 * @Author: LetMeFly
 * @Date: 2024-10-23 22:54:54
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-23 22:56:59
 */
class Solution {
    public long countCompleteDayPairs(int[] hours) {
        long[] bin = new long[24];
        for (int t : hours) {
            bin[t % 24]++;
        }
        long ans = bin[0] * (bin[0] - 1) / 2 + bin[12] * (bin[12] - 1) / 2;
        for (int i = 1; i < 12; i++) {
            ans += bin[i] * bin[24 - i];
        }
        return ans;
    }
}