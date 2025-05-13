/*
 * @Author: LetMeFly
 * @Date: 2025-05-13 09:02:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-13 09:19:43
 */

class Solution {
    private final int MOD = 1000000007;

    public int lengthAfterTransformations(String s, int t) {
        int[] cnt = new int[26];
        for (int i = 0; i < s.length(); i++) {
            cnt[s.charAt(i) - 'a']++;
        }
        int ans = s.length();
        while (t-- > 0) {
            int z = cnt[25];
            for (int i = 24; i >= 0; i--) {
                cnt[i + 1] = cnt[i];
            }
            cnt[0] = z;
            cnt[1] = (cnt[1] + z) % MOD;
            ans = (ans + z) % MOD;
        }
        return ans;
    }
}