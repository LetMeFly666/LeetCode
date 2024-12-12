/*
 * @Author: LetMeFly
 * @Date: 2024-12-12 14:41:47
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-12 14:45:03
 */
import java.util.Arrays;

class Solution {
    public long maxSpending(int[][] values) {
        int[] loc = new int[values.length];
        Arrays.fill(loc, values[0].length - 1);
        long ans = 0, th = 1;
        int cnt = values.length * values[0].length;
        while (th <= cnt) {
            int m = 100000000, mLoc = 0;
            for (int i = 0; i < values.length; i++) {
                if (loc[i] >= 0 && values[i][loc[i]] < m) {
                    m = values[i][loc[i]];
                    mLoc = i;
                }
            }
            ans += values[mLoc][loc[mLoc]] * th;
            th++;
            loc[mLoc]--;
        }
        return ans;
    }
}