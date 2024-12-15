/*
 * @Author: LetMeFly
 * @Date: 2024-12-15 15:09:49
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-15 15:13:47
 */
import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;

class Solution {
    public int minSetSize(int[] arr) {
        Map<Integer, Integer> ma = new HashMap<>();
        for (int t : arr) {
            ma.merge(t, 1, Integer::sum);
        }
        List<Integer> times = new ArrayList<>(ma.values());
        times.sort((a, b) -> b - a);
        int ans = 0;
        for (int cnt = 0, i = 0; cnt < arr.length / 2; ans++, i++) {
            cnt += times.get(i);
        }
        return ans;
    }
}