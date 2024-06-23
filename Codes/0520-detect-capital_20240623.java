/*
 * @Author: LetMeFly
 * @Date: 2024-06-23 19:00:47
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-23 19:03:20
 */
class Solution {
    public boolean detectCapitalUse(String word) {
        int cntLower = 0;
        for (int i = 1; i < word.length(); i++) {
            if (Character.isLowerCase(word.charAt(i))) {
                cntLower++;
            }
        }
        return cntLower == word.length() - 1 || (cntLower == 0 && Character.isUpperCase(word.charAt(0)));
    }
}