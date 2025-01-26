/*
 * @Author: LetMeFly
 * @Date: 2025-01-26 08:02:41
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-26 08:10:08
 */
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

class Solution {
    private List<List<Integer>> ans;
    private List<Integer> now;
    private int[] c;

    private void dfs(int target, int index) {
        if (target == 0) {
            ans.add(new ArrayList<>(now));
            return;
        }
        if (index == c.length || target < 0) {
            return;
        }
        now.add(c[index]);
        dfs(target - c[index], index + 1);
        now.remove(now.size() - 1);
        int next = index;
        while (++next < c.length && c[next] == c[index]);
        dfs(target, next);
    }

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        c = candidates;
        ans = new ArrayList<>();
        now = new ArrayList<>();
        dfs(target, 0);
        return ans;
    }
}