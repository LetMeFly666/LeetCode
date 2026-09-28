/*
 * @Author: LetMeFly
 * @Date: 2026-09-28 08:10:10
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-28 08:20:54
 */
class Solution {
    public int maxDepth(String s) {
        int ans = 0;
        for (int i = 0, n = s.length(), layer = 0; i < n; i++) {
            if (s.charAt(i) == '(') {
                ans = max(ans, ++layer);
            } else if (s.charAt(i) == ')') {
                layer--;
            }
        }
        return ans;
    }
}
