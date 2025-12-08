/*
 * @Author: LetMeFly
 * @Date: 2025-12-08 18:40:41
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-08 18:59:47
 */
class Solution {
    public int countTriples(int n) {
        int ans = 0;
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                int k = a * a + b * b;
                int c = (int)Math.sqrt(k);
                if (c <= n && c * c == k) {
                    ans++;
                }
            }
        }
        return ans;
    }
}