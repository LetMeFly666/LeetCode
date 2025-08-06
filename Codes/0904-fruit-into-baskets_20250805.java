/*
 * @Author: LetMeFly
 * @Date: 2025-08-05 10:28:59
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-06 18:42:21
 */
import java.util.Map;
import java.util.HashMap;

class Solution {
    public int totalFruit(int[] fruits) {
        int ans = 0;
        Map<Integer, Integer> window = new HashMap<>();
        for (int l = 0, r = 0; r < fruits.length; r++) {
            window.merge(fruits[r], 1, Integer::sum);
            while (window.size() > 2) {
                window.merge(fruits[l], -1, Integer::sum);
                if (window.get(fruits[l]) == 0) {
                    window.remove(fruits[l]);
                }
                l--;
            }
            ans = Math.max(ans, r - l + 1);
        }
        return ans;
    }
}