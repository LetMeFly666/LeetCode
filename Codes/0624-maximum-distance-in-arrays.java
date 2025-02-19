/*
 * @Author: LetMeFly
 * @Date: 2025-02-19 17:47:53
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-19 17:51:18
 */
import java.util.List;


class Solution {
    public int maxDistance(List<List<Integer>> arrays) {
        int ans = 0;
        int m = 100000, M = -100000;
        for (List<Integer> a : arrays) {
            ans = Math.max(ans, Math.max(a.get(a.size() - 1) - m, M - a.get(0)));
            m = Math.min(m, a.get(0));
            M = Math.max(M, a.get(a.size() - 1));
        }
        return ans;
    }
}