/*
 * @Author: LetMeFly
 * @Date: 2024-08-14 23:36:10
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-08-14 23:38:18
 */
class Solution {
    public boolean[] isArraySpecial(int[] nums, int[][] queries) {
        int cnt = 0;
        for (int i = 0; i < nums.length - 1; i++) {
            boolean same = nums[i] % 2 == nums[i + 1] % 2;
            nums[i] = cnt;
            cnt += same ? 1 : 0;
        }
        nums[nums.length - 1] = cnt;
        boolean[] ans = new boolean[queries.length];
        for (int i = 0; i < queries.length; i++) {
            ans[i] = nums[queries[i][0]] == nums[queries[i][1]];
        }
        return ans;
    }
}