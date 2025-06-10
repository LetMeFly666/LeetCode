/*
 * @Author: LetMeFly
 * @Date: 2025-06-10 23:07:14
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-10 23:40:04
 */
class Solution {
    public int maxDifference(String s) {
        int[] cnt = new int[26];
        for (char c : s.toCharArray()) {
            cnt[c - 'a']++;
        }
        int a1 = 0, a2 = 100;
        for (int t : cnt) {
            if (t % 2 == 1) {
                a1 = Math.max(a1, t);
            } else if (t > 0) {
                a2 = Math.min(a2, t);
            }
        }
        return a1 - a2;
    }
}