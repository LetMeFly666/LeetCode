/*
 * @Author: LetMeFly
 * @Date: 2024-06-07 20:23:10
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-07 20:24:19
 */
class Solution {
    public int maxOperations(int[] nums) {
        int ans = 1;
        int val = nums[0] + nums[1];
        for (int i = 2; i < nums.length - 1; i += 2) {
            if (nums[i] + nums[i + 1] != val) {
                break;
            }
            ans++;
        }
        return ans;
    }
}