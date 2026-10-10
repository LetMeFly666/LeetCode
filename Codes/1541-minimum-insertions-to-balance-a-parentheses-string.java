/*
 * @Author: LetMeFly
 * @Date: 2026-10-09 08:25:57
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-09 11:22:03
 */
class Solution {
    public int minInsertions(String s) {
        int ans = 0;
        int diff = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                diff++;
            } else {
                if (diff > 0) {
                    diff--;
                } else {
                    ans++;
                }
                if (i + 1 < s.length() && s.charAt(i + 1) == ')') {
                    i++;
                } else {
                    ans++;
                }
            }
        }
        return ans + diff * 2;
    }
}
