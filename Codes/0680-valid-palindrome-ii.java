/*
 * @Author: LetMeFly
 * @Date: 2025-02-03 08:57:34
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-03 09:01:29
 */
class Solution {
    private boolean isOk(String s, int l, int r) {
        for (; l < r; l++, r--) {
            if (s.charAt(l) != s.charAt(r)) {
                return false;
            }
        }
        return true;
    }

    public boolean validPalindrome(String s) {
        for (int l = 0, r = s.length() - 1; l < r; l++, r--) {
            if (s.charAt(l) != s.charAt(r)) {
                return isOk(s, l, r - 1) || isOk(s, l + 1, r);
            }
        }
        return true;
    }
}