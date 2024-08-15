/*
 * @Author: LetMeFly
 * @Date: 2024-08-15 23:59:52
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-08-16 00:06:13
 */
import java.util.List;

class Solution {
    public int maxScore(List<List<Integer>> grid) {
        int ans = -100000000;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.get(0).size(); j++) {
                int original = grid.get(i).get(j);
                if (i > 0) {
                    grid.get(i).set(j, Math.min(grid.get(i).get(j), grid.get(i - 1).get(j)));
                    ans = Math.max(ans, original - grid.get(i - 1).get(j));
                }
                if (j > 0) {
                    grid.get(i).set(j, Math.min(grid.get(i).get(j), grid.get(i).get(j - 1)));
                    ans = Math.max(ans, original - grid.get(i).get(j - 1));
                }
            }
        }
        return ans;
    }
}