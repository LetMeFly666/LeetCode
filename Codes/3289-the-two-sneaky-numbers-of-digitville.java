/*
 * @Author: LetMeFly
 * @Date: 2025-10-31 22:19:33
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-31 22:27:27
 */
import java.util.Set;
import java.util.HashSet;

class Solution {
    public int[] getSneakyNumbers(int[] nums) {
        int[] ans = new int[2];
        int already = 0;
        Set<Integer> se = new HashSet<>();
        for (int t : nums) {
            if (se.contains(t)) {
                ans[already++] = t;
            } else {
                se.add(t);
            }
        }
        return ans;
    }
}