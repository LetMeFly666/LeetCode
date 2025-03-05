/*
 * @Author: LetMeFly
 * @Date: 2025-03-05 16:00:14
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-05 16:02:39
 */
class Solution {
    public String breakPalindrome(String palindrome) {
        if (palindrome.length() == 1) {
            return new String();
        }
        char[] s = palindrome.toCharArray();
        for (int i = 0; i < s.length / 2; i++) {
            if (s[i] != 'a') {
                s[i] = 'a';
                return new String(s);
            }
        }
        s[s.length - 1] = 'b';
        return new String(s);
    }
}