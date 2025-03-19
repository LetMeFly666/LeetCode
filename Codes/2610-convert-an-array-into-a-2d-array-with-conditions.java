/*
 * @Author: LetMeFly
 * @Date: 2025-03-19 19:58:16
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-19 20:03:10
 */
import java.util.HashMap;
import java.util.Map;
import java.util.ArrayList;
import java.util.List;


class Solution {
    public List<List<Integer>> findMatrix(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        Map<Integer, Integer> ma = new HashMap<>();
        for (int t : nums) {
            ma.merge(t, 1, Integer::sum);
            if (ma.get(t) > ans.size()) {
                ans.add(new ArrayList<>());
            }
            ans.get(ma.get(t) - 1).add(t);
        }
        return ans;
    }
}