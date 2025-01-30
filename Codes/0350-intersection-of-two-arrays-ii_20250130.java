/*
 * @Author: LetMeFly
 * @Date: 2025-01-30 08:21:39
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-30 08:25:09
 */
import java.util.HashMap;
import java.util.Map;
import java.util.ArrayList;
import java.util.List;

class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        Map<Integer, Integer> ma = new HashMap<>();
        for (int t : nums1) {
            ma.merge(t, 1, Integer::sum);
        }
        List<Integer> temp = new ArrayList<>();
        for (int t : nums2) {
            int c = ma.getOrDefault(t, 0);
            if (c > 0) {
                temp.add(t);
                ma.put(t, c - 1);
            }
        }
        return temp.stream().mapToInt(i -> i).toArray();
    }
}