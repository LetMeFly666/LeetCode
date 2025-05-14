/*
 * @Author: LetMeFly
 * @Date: 2025-05-14 22:01:41
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-14 23:58:14
 */
import java.util.List;

class Solution {
    private final int MOD = 1000000007;

    private long[][] pow(long[][] a, int b) {
        long[][] ans = new long[26][26];
        for (int i = 0; i < 26; i++) {
            ans[i][i] = 1;
        }
        while (b > 0) {
            if ((b & 1) == 1) {
                ans = mul(ans, a);
            }
            a = mul(a, a);
            b >>= 1;
        }
        return ans;
    }

    private long[][] mul(long[][]a, long[][] b) {
        long[][] ans = new long[26][26];
        for (int i = 0; i < 26; i++) {
            for (int k = 0; k < 26; k++) {
                for (int j = 0; j < 26; j++) {
                    ans[i][j] = (ans[i][j] + a[i][k] * b[k][j] % MOD) % MOD;
                }
            }
        }
        return ans;
    }

    public int lengthAfterTransformations(String s, int t, List<Integer> nums) {
        long[][] M = new long[26][26];
        for (int i = 0; i < 26; i++) {
            for (int j = 1; i <= nums.get(i); j++) {
                M[i][(i + j) % MOD] = 1;
            }
        }
        long[][] Mt = pow(M, t);
        long[] cnt = new long[26];
        for (int i = 0; i < s.length(); i++) {
            cnt[s.charAt(i) - 'a']++;
        }
        long ans = 0;
        for (int i = 0; i < 26; i++) {
            long sum = 0;
            for (int j = 0; j < 26; j++) {
                sum += Mt[i][j];
            }
            sum %= MOD;
            ans = (ans + sum * cnt[i]) % MOD;
        }
        return (int)ans;
    }
}