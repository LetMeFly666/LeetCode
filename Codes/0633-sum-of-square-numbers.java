/*
 * @Author: LetMeFly
 * @Date: 2024-11-04 19:47:30
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-04 19:48:52
 */
class Solution {
    public boolean judgeSquareSum(int c) {
        for (int a = (int)Math.sqrt(c); a >= 0; a--) {
            int b = (int)Math.sqrt(c - a * a);
            if (a * a + b * b == c) {
                return true;
            }
        }
        return false;
    }
}