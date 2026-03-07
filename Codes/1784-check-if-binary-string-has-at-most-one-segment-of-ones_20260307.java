/*
 * @Author: LetMeFly
 * @Date: 2026-03-07 13:14:24
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-03-07 13:17:43
 */
class Solution {
    public boolean checkOnesSegment(String s) {
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i - 1) == '0' && s.charAt(i) == '1') {
                return false;
            }
        }
        return true;
    }
}