/*
 * @Author: LetMeFly
 * @Date: 2026-10-08 08:52:58
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-08 09:24:07
 */
class Solution {
    public String removeOuterParentheses(String s) {
        StringBuilder ans = new StringBuilder();
        for (int i = 0, n = s.length(), layer = 0; i < n; i++) {
            boolean skip = false;
            if (s.charAt(i) == '(') {
                if (layer++ == 0) {
                    skip = true;
                }
            } else {
                if (--layer == 0) {
                    skip = true;
                }
            }
            if (!skip) {
                ans.append(s.charAt(i));
            }
        }
        return ans.toString();
    }
}
