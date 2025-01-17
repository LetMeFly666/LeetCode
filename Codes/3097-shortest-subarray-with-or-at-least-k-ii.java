/*
 * @Author: LetMeFly
 * @Date: 2025-01-17 12:30:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-17 12:41:22
 */
class Solution {
    private int calc(int[] cnt) {
        int ans = 0;
        for (int i = 0; i < 30; i++) {
            if (cnt[i] > 0) {
                ans |= 1 << i;
            }
        }
        return ans;
    }

    private void add(int[] cnt, int a) {
        for (int i = 0; i < 30; i++) {
            cnt[i] += a >> i & 1;
        }
    }

    private void del(int[] cnt, int a) {
        for (int i = 0; i < 30; i++) {
            cnt[i] -= a >> i & 1;
        }
    }

    public int minimumSubarrayLength(int[] nums, int k) {
        if (k == 0) {
            return 1;
        }
        int ans = 1000000;
        int[] cnt = new int[30];
        for (int l = 0, r = 0; l < nums.length; l++) {
            if (l > 0) {
                del(cnt, nums[l - 1]);
            }
            while (r < nums.length && calc(cnt) < k) {
                add(cnt, nums[r++]);
            }
            if (calc(cnt) >= k) {
                ans = Math.min(ans, r - l);
            }
        }
        return ans == 1000000 ? -1 : ans;
    }
}