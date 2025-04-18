/*
 * @Author: LetMeFly
 * @Date: 2025-04-18 10:29:32
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-18 10:34:19
 */
import java.util.Map;
import java.util.HashMap;

class Solution {
    public long countBadPairs(int[] nums) {
        long ans = (long)nums.length * (nums.length - 1) / 2;
        Map<Integer, Integer> times = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            ans -= times.merge(nums[i] - i, 1, Integer::sum) - 1;
        }
        return ans;
    }
}