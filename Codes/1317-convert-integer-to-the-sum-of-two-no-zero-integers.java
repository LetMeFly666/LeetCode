/*
 * @Author: LetMeFly
 * @Date: 2025-09-08 23:05:58
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-08 23:19:08
 */
class Solution {
    private boolean non0(int n) {
        while (n > 0) {
            if (n % 10 == 0) {
                return false;
            }
            n /= 10;
        }
        return true;
    }

    public int[] getNoZeroIntegers(int n) {
        for (int i = 1; i < n; i++) {
            if (non0(i) && non0(n - i)) {
                return new int[]{i, n - i};
            }
        }
        return new int[]{};
    }
}