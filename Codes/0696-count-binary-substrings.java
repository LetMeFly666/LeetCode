/*
 * @Author: LetMeFly
 * @Date: 2026-02-19 11:16:44
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-19 11:30:02
 */
class Solution {
    public int countBinarySubstrings(String s) {
        int ans = 0;
        for (int i = 1, n = s.length(), cnt = 1, lastCnt = 0; i <= n; i++) {
            if (i == n || s.charAt(i) != s.charAt(i - 1)) {
                ans += Math.min(cnt, lastCnt);
                lastCnt = cnt;
                cnt = 0;
            }
            cnt++;
        }
        return ans;
    }
}