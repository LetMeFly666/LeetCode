/*
 * @Author: LetMeFly
 * @Date: 2026-01-01 15:40:30
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-01 15:59:15
 */
class Solution {
    public int[] plusOne(int[] digits) {
        int cnt = 1;
        for (int i = digits.length - 1; i >= 0; i--) {
            digits[i] += cnt;
            cnt = digits[i] / 10;
            digits[i] %= 10;
        }
        if (cnt > 0) {
            int[] ans = new int[digits.length + 1];
            ans[0] = cnt;
            for (int i = 0; i < digits.length; i++) {
                ans[i + 1] = digits[i];
            }
            return ans;
        }
        return digits;
    }
}