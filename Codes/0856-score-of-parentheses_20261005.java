/*
 * @Author: LetMeFly
 * @Date: 2026-10-05 16:38:39
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-05 16:44:16
 */
class Solution {
    public int scoreOfParentheses(String s) {
        int ans = 0;
        for (int i = 0, n = s.length(), layer = 0; i < n; i++) {
            if (s.charAt(i) == '(') {
                layer++;
            } else {
                layer--;
                if (s.charAt(i - 1) == '(') {
                    ans += 1 << layer;
                }
            }
        }
        return ans;
    }
}
