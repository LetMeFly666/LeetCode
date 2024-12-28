/*
 * @Author: LetMeFly
 * @Date: 2024-12-28 14:43:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-28 14:45:25
 */
import java.util.HashMap;

class Solution {
    public boolean isPossibleToSplit(int[] nums) {
        HashMap<Integer, Integer> times = new HashMap<>();
        for (int t : nums) {
            if (times.merge(t, 1, Integer::sum) > 2) {
                return false;
            }
        }
        return true;
    }
}