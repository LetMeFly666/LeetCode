/*
 * @Author: LetMeFly
 * @Date: 2024-12-26 15:42:36
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-26 15:44:38
 */
class Solution {
    public boolean isSubstringPresent(String s) {
        boolean[][] visited = new boolean[26][26];
        for (int i = 1; i < s.length(); i++) {
            visited[s.charAt(i - 1) - 'a'][s.charAt(i) - 'a'] = true;
            if (visited[s.charAt(i) - 'a'][s.charAt(i - 1) - 'a']) {
                return true;
            }
        }
        return false;
    }
}