/*
 * @Author: LetMeFly
 * @Date: 2025-02-06 13:57:34
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-06 14:13:00
 */
import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;

class Solution {
    private List<List<Integer>> ans = new ArrayList<>();
    private List<Integer> now = new ArrayList<>();
    private int[] nums;
    private boolean[] visited;

    private void dfs(int n) {
        if (n == nums.length) {
            ans.add(new ArrayList<Integer>(now));
            return;
        }
        for (int i = 0; i < nums.length; i++) {
            if (visited[i] || i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) {
                continue;
            }
            now.add(nums[i]);
            visited[i] = true;
            dfs(n + 1);
            visited[i] = false;
            now.remove(now.size() - 1);
        }
    }

    public List<List<Integer>> permuteUnique(int[] nums) {
        Arrays.sort(nums);
        this.nums = nums;
        visited = new boolean[nums.length];
        dfs(0);
        return ans;
    }
}