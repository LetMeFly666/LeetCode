/*
 * @Author: LetMeFly
 * @Date: 2025-03-27 22:08:30
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-27 22:11:31
 */
class Solution {
    public long minimumCost(String s) {
        long ans = 0;
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) != s.charAt(i - 1)) {
                ans += Math.min(i, s.length() - i);
            }
        }
        return ans;
    }
}