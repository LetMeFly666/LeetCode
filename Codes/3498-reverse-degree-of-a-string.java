/*
 * @Author: LetMeFly
 * @Date: 2026-09-20 10:25:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-20 10:40:05
 */
class Solution {
    public int reverseDegree(String s) {
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            ans += (i + 1) * (26 - s.charAt(i) + 'a');
        }
        return ans;
    }
}
