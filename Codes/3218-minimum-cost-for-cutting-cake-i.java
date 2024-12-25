/*
 * @Author: LetMeFly
 * @Date: 2024-12-25 20:36:16
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-25 20:42:05
 */
class Solution {
    int[][][][] cache;
    int[] h, v;

    private int dfs(int ia, int ib, int ja, int jb) {
        if (cache[ia][ib][ja][jb] > 0 || (ib == ia + 1 && jb == ja + 1)) {
            return cache[ia][ib][ja][jb];
        }
        int ans = 1000000000;
        for (int ic = ia + 1; ic < ib; ic++) {
            ans = Math.min(ans, h[ic - 1] + dfs(ia, ic, ja, jb) + dfs(ic, ib, ja, jb));
        }
        for (int jc = ja + 1; jc < jb; jc++) {
            ans = Math.min(ans, v[jc - 1] + dfs(ia, ib, ja, jc) + dfs(ia, ib, jc, jb));
        }
        cache[ia][ib][ja][jb] = ans;
        return ans;
    }

    public int minimumCost(int m, int n, int[] horizontalCut, int[] verticalCut) {
        cache = new int[m][m + 1][n][n + 1];
        h = horizontalCut;
        v = verticalCut;
        return dfs(0, m, 0, n);
    }
}