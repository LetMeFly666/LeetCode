/*
 * @Author: LetMeFly
 * @Date: 2025-10-30 22:39:36
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-30 23:07:34
 */
import java.util.Map;
import java.util.HashMap;
import java.util.Arrays;

class Solution {
    public int maxFrequency(int[] nums, int k, int numOperations) {
        Arrays.sort(nums);
        Map<Integer, Integer> frequency = new HashMap<>();
        for (int t : nums) {
            frequency.merge(t, 1, Integer::sum);  // 这个api挺容易忘的
        }
        int ans = 0, n = nums.length;
        for (int l = 0, r = 0, target = nums[0]; target <= nums[n - 1]; target++) {
            while (target - nums[l] > k) {
                l++;
            }
            while (r < n && nums[r] - target <= k) {
                r++;
            }
            ans = Math.max(ans, Math.min(r - l, numOperations + frequency.getOrDefault(target, 0)));
        }
        return ans;
    }
}