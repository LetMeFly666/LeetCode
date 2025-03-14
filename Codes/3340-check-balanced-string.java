/*
 * @Author: LetMeFly
 * @Date: 2025-03-14 09:35:26
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-14 09:35:26
 */
class Solution {
    public boolean isBalanced(String num) {
        int cnt = 0;
        for (int i = 0; i < num.length(); i++) {
            if (i % 2 == 0) {
                cnt += num.charAt(i) - 48;
            } else {
                cnt -= num.charAt(i) - 48;
            }
        }
        return cnt == 0;
    }
}