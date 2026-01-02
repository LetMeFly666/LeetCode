/*
 * @Author: LetMeFly
 * @Date: 2026-01-02 17:49:22
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-02 17:52:19
 */
class Solution {
    public int repeatedNTimes(int[] nums) {
        int ans = 0, hp = 0;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == nums[0]) {
                return nums[0];
            }
            if (hp == 0) {
                ans = nums[i];
                hp = 1;
            } else if (ans == nums[i]) {
                hp++;
            } else {
                hp--;
            }
        }
        return ans;
    }
}