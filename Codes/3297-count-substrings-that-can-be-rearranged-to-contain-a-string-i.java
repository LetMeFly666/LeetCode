/*
 * @Author: LetMeFly
 * @Date: 2025-01-09 12:46:14
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-09 12:51:13
 */
class Solution {
    private boolean ok(int[] a, int[] b) {
        for (int i = 0; i < 26; i++) {
            if (a[i] < b[i]) {
                return false;
            }
        }
        return true;
    }

    public long validSubstringCount(String word1, String word2) {
        int[] cnt1 = new int[26], cnt2 = new int[26];
        for (char c : word2.toCharArray()) {
            cnt2[c - 'a']++;
        }
        long ans = 0;
        for (int l = 0, r = 0; l < word1.length(); l++) {
            if (l > 0) {
                cnt1[word1.charAt(l - 1) - 'a']--;
            }
            while (!ok(cnt1, cnt2)) {
                if (r == word1.length()) {
                    return ans;
                }
                cnt1[word1.charAt(r++) - 'a']++;
            }
            ans += word1.length() - r + 1;
        }
        return ans;
    }
}