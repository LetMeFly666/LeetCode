/*
 * @Author: LetMeFly
 * @Date: 2025-01-08 15:37:06
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-08 15:41:37
 */
class Solution {
    public String largestGoodInteger(String num) {
        char M = '/';
        for (int i = 2; i < num.length(); i++) {
            if (num.charAt(i) == num.charAt(i - 1) && num.charAt(i) == num.charAt(i - 2)) {
                M = (char) Math.max(M, num.charAt(i));
            }
        }
        return M == '/' ? "" : "" + M + M + M;
    }
}