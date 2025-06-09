/*
 * @Author: LetMeFly
 * @Date: 2025-06-09 10:09:21
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-09 21:59:20
 */
import java.util.List;
import java.util.ArrayList;

class Solution {
    public List<Integer> lexicalOrder(int n) {
        List<Integer> ans = new ArrayList<>();
        for (int now = 1, i = 0; i < n; i++) {
            ans.offer(now);
            if (now * 10 <= n) {
                now *= 10;
            } else {
                while (now % 10 == 9 || now == n) {
                    now /= 10;
                }
                now++;
            }
        }
        return ans;
    }
}