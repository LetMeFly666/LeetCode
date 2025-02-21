/*
 * @Author: LetMeFly
 * @Date: 2025-02-21 13:05:59
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-21 14:39:29
 */
import java.util.Map;
import java.util.HashMap;

class Solution {
    private String floor;
    private int perLen;
    private Map<Integer, Integer> cache = new HashMap<>();

    private int dfs(int n, int index) {
        int code = n * 1000 + index;
        if (cache.containsKey(code)) {
            return cache.get(code);
        }
        if (n * perLen >= floor.length() - index) {
            cache.put(code, 0);
            return 0;
        }
        int ans = dfs(n, index + 1);
        if (floor.charAt(index) == '1') {
            ans++;
        }
        if (n > 0) {
            ans = Math.min(ans, dfs(n - 1, index + perLen));
        }
        cache.put(code, ans);
        return ans;
    }

    public int minimumWhiteTiles(String floor, int numCarpets, int carpetLen) {
        this.floor = floor;
        perLen = carpetLen;
        return dfs(numCarpets, 0);
    }
}