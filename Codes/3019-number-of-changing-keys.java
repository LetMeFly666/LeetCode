/*
 * @Author: LetMeFly
 * @Date: 2025-01-07 13:10:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-07 13:11:25
 */
class Solution {
    public int countKeyChanges(String s) {
        int ans = 0;
        for (int i = 1; i < s.length(); i++) {
            if (Character.toLowerCase(s.charAt(i)) != Character.toLowerCase(s.charAt(i - 1))) {
                ans++;
            }
        }
        return ans;
    }
}