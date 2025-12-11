/*
 * @Author: LetMeFly
 * @Date: 2025-12-11 13:14:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-11 13:40:24
 */
import java.util.Arrays;

class Solution {
    public int countCoveredBuildings(int n, int[][] buildings) {
        n++;
        int[] xm = new int[n];
        int[] xM = new int[n];
        int[] ym = new int[n];
        int[] yM = new int[n];
        Arrays.fill(xm, n);
        Arrays.fill(ym, n);

        for (int[] building : buildings) {
            int x = building[0], y = building[1];
            xm[x] = Math.min(xm[x], y);
            xM[x] = Math.max(xM[x], y);
            ym[y] = Math.min(ym[y], x);
            yM[y] = Math.max(yM[y], x);
        }

        int ans = 0;
        for (int[] building : buildings) {
            int x = building[0], y = building[1];
            if (xm[x] < y && y < xM[x] && ym[y] < x && x < yM[y]) {
                ans++;
            }
        }
        return ans;
    }
}