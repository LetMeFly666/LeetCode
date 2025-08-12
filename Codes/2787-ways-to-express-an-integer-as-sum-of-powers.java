/*
 * @Author: LetMeFly
 * @Date: 2025-08-12 09:48:56
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-12 21:46:26
 */
import java.util.List;
import java.util.ArrayList;

class Solution {
    public int numberOfWays(int n, int x) {
        List<Integer> dp = new ArrayList<>(n + 1);
        dp.get(0) = 1;
        for (int th = 1; ; th++) {
            int p = Math.pow(th, x);
            if (p > n) {
                break;
            }
            for (int i = n; i >= p; i--) {
                dp.get(i) = ((long)dp.get(i) + dp.get(i - p)) % 1000000007;
            }
        }
        return dp.get(n);
    }
}