/*
 * @Author: LetMeFly
 * @Date: 2025-01-29 11:53:14
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-29 11:55:24
 */
import java.util.HashMap;

class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        HashMap<Integer, Integer> ma = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            if (i - ma.getOrDefault(nums[i], -1000000) <= k) {
                return true;
            }
            ma.put(nums[i], i);
        }
        return false;
    }
}