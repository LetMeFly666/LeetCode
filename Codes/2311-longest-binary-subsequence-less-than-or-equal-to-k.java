/*
 * @Author: LetMeFly
 * @Date: 2025-06-26 22:16:30
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-26 22:45:37
 */
class Solution {
    public int longestSubsequence(String s, int k) {
        int ans = 0, n = s.length(), lenK = 32 - Integer.numberOfLeadingZeros(k), val = 0;
        for (int i = 0; i < n; i++) {
            if (s.charAt(n - i - 1) == '0') {
                ans++;
                continue;
            }
            if (i < lenK && val + (1 << i) <= k) {
                val += 1 << i;
                ans++;
            }
        }
        return ans;
    }
}