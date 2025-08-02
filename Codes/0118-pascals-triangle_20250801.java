/*
 * @Author: LetMeFly
 * @Date: 2025-08-01 23:51:32
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-02 12:47:48
 */
import java.util.List;
import java.util.ArrayList;

class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> ans = new ArrayList<>(numRows);
        ans.add(List.of(1));
        for (int i = 1; i < numRows; i++) {
            ans.add(new ArrayList<>(i + 1));
            ans.get(i).add(1);
            for (int j = 1; j < i; j++) {
                ans.get(i).add(ans.get(i - 1).get(j - 1) + ans.get(i - 1).get(j));
            }
            ans.get(i).add(1);
        }
        return ans;
    }
}