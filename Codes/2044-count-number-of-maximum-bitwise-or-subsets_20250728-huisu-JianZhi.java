/*
 * @Author: LetMeFly
 * @Date: 2025-07-28 13:38:06
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-28 20:43:13
 */
class Solution {
    private int ans = 0;
    private int M = 0;
    private int[] nums;

    private void dfs(int th, int now) {
        if (now == M) {
            ans += 1 << (nums.length - th);
            return;
        }
        if (th == nums.length) {
            return;
        }
        dfs(th + 1, now);
        dfs(th + 1, now | nums[th]);
    }

    public int countMaxOrSubsets(int[] nums) {
        this.nums = nums;
        for (int t : nums) {
            M |= t;
        }
        dfs(0, 0);
        return ans;
    }
}