/*
 * @Author: LetMeFly
 * @Date: 2025-02-13 13:43:06
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-13 13:48:29
 */
class Solution {
    private int[] nums;

    private boolean check(int op, int m) {
        for (int t : nums) {
            op -= (t - 1) / m;
        }
        return op >= 0;
    }

    private int max() {
        int ans = nums[0];
        for (int t : nums) {
            ans = Math.max(ans, t);
        }
        return ans;
    }
    public int minimumSize(int[] nums, int maxOperations) {
        this.nums = nums;
        int l = 1, r = max();
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(maxOperations, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }
}