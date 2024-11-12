/*
 * @Author: LetMeFly
 * @Date: 2024-11-12 18:14:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-12 18:31:42
 */
class Solution {
    public int countKConstraintSubstrings(String s, int k) {
        int[] cnt = new int[2];
        int ans = 0;
        for (int l = 0, r = 0; r < s.length(); r++) {
            cnt[s.charAt(r) - '0']++;
            while (cnt[0] > k && cnt[1] > k) {
                cnt[s.charAt(l++) - '0']--;
            }
            ans += r - l + 1;
        }
        return ans;
    }
}