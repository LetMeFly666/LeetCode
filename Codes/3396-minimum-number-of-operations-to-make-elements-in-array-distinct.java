/*
 * @Author: LetMeFly
 * @Date: 2025-04-08 21:57:38
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-08 21:59:04
 */
import java.util.Set;
import java.util.HashSet;

class Solution {
    public int minimumOperations(int[] nums) {
        Set<Integer> se = new HashSet<>();
        for (int i = nums.length - 1; i >= 0; i--) {
            if (!se.add(nums[i])) {
                return i / 3 + 1;
            }
        }
        return 0;
    }
}