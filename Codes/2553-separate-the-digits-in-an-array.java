/*
 * @Author: LetMeFly
 * @Date: 2026-05-11 21:16:18
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-05-11 21:32:57
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

        return ans;
    }
}
