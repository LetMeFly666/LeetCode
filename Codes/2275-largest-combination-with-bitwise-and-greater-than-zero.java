/*
 * @Author: LetMeFly
 * @Date: 2025-01-14 17:16:21
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-14 17:16:23
 */
class Solution {
    public int largestCombination(int[] candidates) {
        int ans = 0;
        for (int i = 0; i < 24; i++) {
            int cnt = 0;
            for (int t : candidates) {
                cnt += t >> i & 1;
            }
            ans = Math.max(ans, cnt);
        }
        return ans;
    }
}