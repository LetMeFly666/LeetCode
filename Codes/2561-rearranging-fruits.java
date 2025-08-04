/*
 * @Author: LetMeFly
 * @Date: 2025-08-03 22:53:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-04 13:46:46
 */
import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;

class Solution {
    public long minCost(int[] basket1, int[] basket2) {
        int m = basket1[0];
        Map<Integer, Integer> timeDiffs = new HashMap<>();
        for (int t : basket1) {
            timeDiffs.merge(t, 1, Integer::sum);
            m = Math.min(m, t);
        }
        for (int t : basket2) {
            timeDiffs.merge(t, -1, Integer::sum);
            m = Math.min(m, t);
        }

        List<Integer> change = new ArrayList<>();
        for (Map.Entry<Integer, Integer> entry : timeDiffs.entrySet()) {
            if (entry.getValue() == 0) {
                continue;
            }
            if (entry.getValue() % 2 != 0) {
                return -1;
            }
            for (int i = 0; i < Math.abs(entry.getValue()) / 2; i++) {
                change.add(entry.getKey());
            }
        }

        long ans = 0;
        change.sort(Integer::compareTo);
        for (int i = 0; i < change.size() / 2; i++) {
            ans += Math.min(2 * m, change.get(i));
        }
        return ans;
    }
}