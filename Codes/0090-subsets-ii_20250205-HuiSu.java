/*
 * @Author: LetMeFly
 * @Date: 2025-02-05 12:29:23
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-05 12:38:09
 */
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

class Solution {
    private List<List<Integer>> ans = new ArrayList<>();
    private List<Integer> now = new ArrayList<>();
    private int[] a;

    private void dfs(int loc) {
        if (loc == a.length) {
            ans.add(new ArrayList<>(now));
            return;
        }
        // 选当前
        now.add(a[loc]);
        dfs(loc + 1);
        now.remove(now.size() - 1);
        // 不选
        int next = loc + 1;
        while (next < a.length && a[next] == a[loc]) {
            next++;
        }
        dfs(next);
    }

    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        a = nums;
        dfs(0);
        return ans;
    }
}