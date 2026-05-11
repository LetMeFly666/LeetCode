/*
 * @Author: LetMeFly
 * @Date: 2026-05-11 21:16:18
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-05-11 21:31:30
 */
class Solution {
    public int[] separateDigits(int[] nums) {
        int cnt = 0;
        for (int t : nums) {
            while (t > 0) {
                cnt++;
                t /= 10;
            }
        }

        int[] ans = new int[cnt];
        for (int i = nums.length - 1, idx = cnt - 1; i >= 0; i--) {
            while (nums[i] > 0) {
                ans[idx--] = nums[i] % 10;
                nums[i] /= 10;
            }
        }

        for (int l = 0, r = cnt - 1, tmp; l < r; l++, r--) {
            tmp = ans[l];
            ans[l] = ans[r];
            ans[r] = tmp;
        }
        return ans;
    }
}
