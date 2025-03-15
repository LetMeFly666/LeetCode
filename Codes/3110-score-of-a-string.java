/*
 * @Author: LetMeFly
 * @Date: 2025-03-15 10:36:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-15 10:36:23
 */
class Solution {
    public int scoreOfString(String s) {
        int ans = 0;
        for (int i = 1; i < s.length(); i++) {
            ans += Math.abs(s.charAt(i) - s.charAt(i - 1));
        }
        return ans;
    }
}