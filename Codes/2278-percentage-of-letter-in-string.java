/*
 * @Author: LetMeFly
 * @Date: 2025-03-31 13:33:36
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-31 13:40:38
 */
class Solution {
    public int percentageLetter(String s, char letter) {
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if (letter == s.charAt(i)) {
                cnt++;
            }
        }
        return cnt * 100 / s.length();
    }
}