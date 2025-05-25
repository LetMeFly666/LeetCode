/*
 * @Author: LetMeFly
 * @Date: 2025-05-25 23:39:17
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-25 23:51:33
 */
class Solution {
    public int longestPalindrome(String[] words) {
        int[][] times = new int[26][26];
        for (String word : words) {
            times[word.charAt(0) - 'a'][word.charAt(1) - 'a']++;
        }
        int side = 0, middle = 0;
        for (int i = 0; i < 26; i++) {
            side += times[i][i] / 2 * 2;
            middle |= times[i][i] % 2;
            for (int j = i + 1; j < 26; j++) {
                side += Math.min(times[i][j], times[j][i]) * 2;
            }
        }
        return (side + middle) * 2;
    }
}