/*
 * @Author: LetMeFly
 * @Date: 2025-06-06 21:49:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-06 22:38:18
 */
// StringBuilder - java.lang
import java.util.Deque;
import java.util.ArrayDeque;

class Solution {
    public String robotWithString(String s) {
        char[] mini = new char[s.length() + 1];
        mini[s.length()] = 'z';
        for (int i = s.length() - 1; i >= 0; i--) {
            mini[i] = Math.min(mini[i + 1], s.charAt(i));
        }
        StringBuilder ans = new StringBuilder(s.length());
        Deque<Character> st = new ArrayDeque<>();
        for (int i = 0; i < s.length(); i++) {
            st.push(s.charAt(i));
            while (!st.isEmpty() && st.peek() <= mini[i + 1]) {
                ans.append(st.pop());
            }
        }
        return ans.toString();
    }
}