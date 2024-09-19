/*
 * @Author: LetMeFly
 * @Date: 2024-09-19 17:52:28
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-09-19 17:55:10
 */
class Solution {
    public int longestContinuousSubstring(String s) {
        int ans = 1, nowCnt = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == s.charAt(i - 1) + 1) {
                nowCnt++;
                ans = Math.max(ans, nowCnt);
            }
            else {
                nowCnt = 1;
            }
        }
        return ans;
    }
}