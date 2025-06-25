/*
 * @Author: LetMeFly
 * @Date: 2025-06-25 22:24:22
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-25 22:41:09
 */
import java.util.List;
import java.util.ArrayList;

class Solution {
    public List<Integer> findKDistantIndices(int[] nums, int key, int k) {
        List<Integer> ans = new ArrayList<>();
        for (int i = 0, j = 0; i < nums.length; i++) {
            if (nums[i] == key) {
                for (j = Math.max(j, i - k); j <= Math.min(nums.length - 1, i + k); j++) {
                    ans.add(j);
                }
            }
        }
        return ans;
    }
}