/*
 * @Author: LetMeFly
 * @Date: 2025-02-22 11:16:28
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-22 11:23:31
 */
import java.util.Map;
import java.util.HashMap;

class Solution {
    private int code(String s) {
        int ans = 0;
        for (char c : s.toCharArray()) {
            ans |= 1 << (c - 'a');
        }
        return ans;
    }

    public int similarPairs(String[] words) {
        Map<Integer, Integer> ma = new HashMap<>();
        int ans = 0;
        for (String s : words) {
            int c = code(s);
            ans += ma.getOrDefault(c, 0);
            ma.merge(c, 1, Integer::sum);
        }
        return ans;
    }
}