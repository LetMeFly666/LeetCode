/*
 * @Author: LetMeFly
 * @Date: 2026-01-02 17:46:44
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-02 17:48:22
 */
import java.util.Set;
import java.util.HashSet;

class Solution {
    public int repeatedNTimes(int[] nums) {
        Set<Integer> visited = new HashSet<>();
        for (int t : nums) {
            if (visited.contains(t)) {
                return t;
            }
            visited.add(t);
        }
        return -1;  // FAKE RETURN
    }
}