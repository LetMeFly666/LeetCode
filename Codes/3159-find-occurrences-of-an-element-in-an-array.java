/*
 * @Author: LetMeFly
 * @Date: 2024-12-27 12:18:32
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-27 12:20:43
 */
import java.util.ArrayList;

class Solution {
    public int[] occurrencesOfElement(int[] nums, int[] queries, int x) {
        ArrayList<Integer> locs = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == x) {
                locs.add(i);
            }
        }
        int[] ans = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            if (queries[i] > locs.size()) {
                ans[i] = -1;
            } else {
                ans[i] = locs.get(queries[i] - 1);
            }
        }
        return ans;
    }
}