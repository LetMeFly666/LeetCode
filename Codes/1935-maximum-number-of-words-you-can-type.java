/*
 * @Author: LetMeFly
 * @Date: 2025-09-15 21:48:47
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-15 22:00:30
 */
import java.util.Set;
import java.util.HashSet;

class Solution {
    public int canBeTypedWords(String text, String brokenLetters) {
        Set<Character> cannot = new HashSet<>();
        for (char c : brokenLetters.toCharArray()) {
            cannot.add(c);
        }
        int ans = 0;
        boolean can = true;
        for (char c : text.toCharArray()) {
            if (c == ' ') {
                ans += can ? 1 : 0;
                can = true;
                continue;
            }
            if (cannot.contains(c)) {
                can = false;
            }
        }
        return ans + (can ? 1 : 0);
    }
}