/*
 * @Author: LetMeFly
 * @Date: 2025-04-24 22:47:48
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-24 23:18:36
 */
import java.util.Set;
import java.util.Map;
import java.util.HashSet;
import java.util.HashMap;

class Solution {
    public int countCompleteSubarrays(int[] nums) {
        Set<Integer> se = new HashSet<>();
        for (int t : nums) {
            se.add(t);
        }
        int allType = se.size();
        Map<Integer, Integer> times = new HashMap<>();
        int ans = 0;
        int l = 0;
        for (int t : nums) {
            times.merge(t, 1, Integer::sum);
            while (times.size() == allType && times.get(nums[l]) > 1) {
                times.merge(nums[l++], -1, Integer::sum);
            }
            if (times.size() == allType) {
                ans += l + 1;
            }
        }
        return ans;
    }
}