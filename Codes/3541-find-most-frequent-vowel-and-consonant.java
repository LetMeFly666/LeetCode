/*
 * @Author: LetMeFly
 * @Date: 2025-09-13 16:07:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-13 16:23:21
 */
class Solution {
    private final static int mask = 1<<0 | 1<<4 | 1<<8 | 1<<14 | 1<<20;

    public int maxFreqSum(String s) {
        int[] times = new int[26];
        for (int i = 0; i < s.length(); i++) {
            times[s.charAt(i) - 'a']++;
        }
        int[] cnt = new int[2];
        for (int i = 0; i < 26; i++) {
            int idx = mask >> i & 1;
            cnt[idx] = Math.max(cnt[idx], times[i]);
        }
        return cnt[0] + cnt[1];
    }
}