/*
 * @Author: LetMeFly
 * @Date: 2024-12-10 15:17:45
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-10 15:29:23
 */
import java.util.Arrays;

class Solution {
    private final int[][] canFrom = {
        {4, 6},  // 0可以来自4，6
        {6, 8},
        {7, 9},
        {4, 8},
        {3, 9, 0},
        {},
        {1, 7, 0},
        {2, 6},
        {1, 3},
        {2, 4}
    };
    private final int mod = 1000000007;

    public int knightDialer(int n) {
        int[] last = new int[10];
        int[] now = new int[10];
        Arrays.fill(last, 1);
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < 10; j++) {
                for (int from : canFrom[j]) {
                    now[j] = (now[j] + last[from]) % mod;
                }
            }
            last = now;
        }
        int ans = 0;
        for (int i = 0; i < 10; i++) {
            ans = (ans + last[i]) % mod;
        }
        return ans;
    }
}