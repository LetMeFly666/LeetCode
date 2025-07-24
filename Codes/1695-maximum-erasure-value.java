/*
 * @Author: LetMeFly
 * @Date: 2025-07-23 10:31:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-24 13:22:02
 */
import java.util.HashSet;
import java.util.Set;

class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        int ans = 0;
        Set<Integer> had = new HashSet<>();
        for (int l = 0, r = 0, cnt = 0; r < nums.length; r++) {
            while (had.contains(nums[r])) {
                had.remove(nums[l]);
                cnt -= nums[l++];
            }
            had.add(nums[r]);
            cnt += nums[r];
            ans = Math.max(ans, cnt);
        }
        return ans;
    }
}