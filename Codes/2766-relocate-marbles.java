/*
 * @Author: LetMeFly
 * @Date: 2024-07-25 12:45:04
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-25 12:48:27
 */
import java.util.Set;
import java.util.HashSet;
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

class Solution {
    public List<Integer> relocateMarbles(int[] nums, int[] moveFrom, int[] moveTo) {
        Set<Integer> se = new HashSet<>(nums.length);  // 预先分配空间，效率更高
        for (int t : nums) {
            se.add(t);
        }
        for (int i = 0; i < moveFrom.length; i++) {
            se.remove(moveFrom[i]);
            se.add(moveTo[i]);
        }
        List<Integer> ans = new ArrayList<>(se);
        Collections.sort(ans);
        return ans;
    }
}