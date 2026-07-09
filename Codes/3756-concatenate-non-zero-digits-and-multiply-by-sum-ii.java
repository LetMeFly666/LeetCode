/*
 * @Author: LetMeFly
 * @Date: 2026-07-09 14:23:02
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-09 14:35:10
 */
// 无编辑器补全、语法检查
class Solution {
    private static final long MOD = 1000000007;
    private static final int N = 100001;
    private static final long[] pow = new long[N + 1];
    private static boolean first = true;

    public Solution() {
        if (!first) {
            return;
        }
        first = false;

        pow[0] = 1;
        for (int i = 1; i <= N; i++) {
            pow[i] = pow[i - 1] * 10 % MOD;
        }
    }

    public int[] sumAndMultiply(String s, int[][] queries) {
        int n = s.length();
        int[] sum = new int[n + 1];
        int[] con = new int[n + 1];
        int[] cnt1 = new int[n + 1];

        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '0') {
                sum[i + 1] = sum[i];
                con[i + 1] = con[i];
                cnt1[i + 1] = cnt1[i];
            } else {
                int v = s.charAt(i) - '0';
                sum[i + 1] = sum[i] + v;
                con[i + 1] = (con[i] * 10 + v) % MOD;
                cnt1[i + 1] = cnt1[i] + 1;
            }
        }

        n = queries.length;
        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            int l = queries[i][0];
            int r = queries[i][1] + 1;
            long su = sum[r] - sum[l];
            long co = (con[r] - con[l] * pow[cnt1[r] - cnt1[l]]) % MOD + MOD;
            ans[i] = (int) (su * co % MOD);
        }
        return ans;
    }
}
