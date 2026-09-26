/*
 * @Author: LetMeFly
 * @Date: 2026-01-31 13:49:56
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-31 14:01:16
 */
class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        for (int i = 0; i < letters.length; i++) {
            if (letters[i] > target) {
                return letters[i];
            }
        }
        return letters[0];
    }
}