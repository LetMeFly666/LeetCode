/*
 * @Author: LetMeFly
 * @Date: 2025-05-22 22:07:10
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-22 23:29:09
 */
class Solution {
    private int[] nums;
    private int[][] queries;

    public boolean check(int n) {
        int[] diff = new int[nums.length + 1];
        for (int i = 0; i < n; i++) {
            diff[queries[i][0]] += queries[i][2];
            diff[queries[i][1] + 1] -= queries[i][2];
        }
        int cnt = 0;
        for (int i = 0; i < nums.length; i++) {
            cnt += diff[i];
            if (nums[i] > cnt) {
                return false;
            }
        }
        return true;
    }

    public int minZeroArray(int[] nums, int[][] queries) {
        this.nums = nums;
        this.queries = queries;
        int l = -1, r = queries.length + 1;
        while (l + 1 < r) {
            int m = (l + r) >> 1;
            if (check(m)) {
                r = m;
            } else {
                l = m;
            }
        }
        return r > queries.length ? -1 : r;
    }
}