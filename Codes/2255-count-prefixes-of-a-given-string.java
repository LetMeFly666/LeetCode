/*
 * @Author: LetMeFly
 * @Date: 2025-03-24 17:53:35
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-24 17:53:41
 */
class Solution {
    public int countPrefixes(String[] words, String s) {
        int ans = 0;
        for (String word : words) {
            ans += s.startsWith(word) ? 1 : 0;
        }
        return ans;
    }
}