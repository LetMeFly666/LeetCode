/*
 * @Author: LetMeFly
 * @Date: 2026-11-22 09:57:21
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-11-22 10:00:56
 */
class Solution {
    public boolean checkString(String s) {
        for (int i = 1, n = s.length(); i < n; i++) {
            if (s.charAt(i - 1) == 'b' && s.charAt(i) == 'a') {
                return false;
            }
        }
        return true;
    }
}
