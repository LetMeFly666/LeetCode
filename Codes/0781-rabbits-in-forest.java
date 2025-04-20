/*
 * @Author: LetMeFly
 * @Date: 2025-04-20 21:06:44
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-20 21:12:27
 */
import java.util.Map;
import java.util.HashMap;

class Solution {
    public int numRabbits(int[] answers) {
        Map<Integer, Integer> times = new HashMap<>();
        for (int t : answers) {
            times.merge(t, 1, Integer::sum);
        }
        int ans = 0;
        // times.forEach((group, total) -> ans += (group + total) / (group + 1) * (group + 1));  // 不可，CE
        for (Map.Entry<Integer, Integer> entry : times.entrySet()) {
            int group = entry.getKey();
            int total = entry.getValue();
            ans += (group + total) / (group + 1) * (group + 1);
        }
        return ans;
    }
}