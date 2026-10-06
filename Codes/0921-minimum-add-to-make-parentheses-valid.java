/*
 * @Author: LetMeFly
 * @Date: 2026-10-06 11:26:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-06 11:30:17
 */
class Solution {
    public int minAddToMakeValid(String s) {
        int ans = 0;
        int diff = 0;
        for (int i = 0, n = s.length(); i < n; i++) {
            if (s.charAt(i) == '(') {
                diff++;
            } else if (diff > 0) {
                diff--;
            } else {
                ans++;
            }
        }
        return ans + diff;
    }
}
