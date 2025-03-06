/*
 * @Author: LetMeFly
 * @Date: 2025-03-06 16:38:18
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-06 16:41:02
 */
import java.util.Map;
import java.util.HashMap;

class Solution {
    public long beautifulSubarrays(int[] nums) {
        Map<Integer, Integer> times = new HashMap<>();
        times.put(0, 1);
        long ans = 0;
        int val = 0;
        for (int t : nums) {
            val ^= t;
            int thisTime = times.getOrDefault(val, 0);
            ans += thisTime;
            times.put(val, ++thisTime);
        }
        return ans;
    }
}