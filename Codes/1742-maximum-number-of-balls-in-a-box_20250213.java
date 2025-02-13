/*
 * @Author: LetMeFly
 * @Date: 2025-02-13 16:22:18
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-13 16:27:51
 */
class Solution {
    private int get(int n) {
        int ans = 0;
        while (n > 0) {
            ans += n % 10;
            n /= 10;
        }
        return ans;
    }
    public int countBalls(int l, int r) {
        int[] cnt = new int[46];
        int ans = 0;
        for (; l <= r; l++) {
            int thisCnt = get(l);
            cnt[thisCnt]++;
            ans = Math.max(ans, cnt[thisCnt]);
        }
        return ans;
    }
}