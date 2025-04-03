/*
 * @Author: LetMeFly
 * @Date: 2025-04-03 23:32:21
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-03 23:38:01
 */
import java.util.Map;
import java.util.HashMap;

class Solution {
    private int[][] q;
    private Map<Integer, Long> cache = new HashMap<>();

    private long dfs(int i) {
        if (i >= q.length) {
            return 0;
        }
        if (cache.containsKey(i)) {
            return cache.get(i);
        }
        long ans = Math.max(dfs(i + 1), dfs(i + q[i][1] + 1) + q[i][0]);
        cache.put(i, ans);
        return ans;
    }

    public long mostPoints(int[][] questions) {
        q = questions;
        return dfs(0);
    }
}