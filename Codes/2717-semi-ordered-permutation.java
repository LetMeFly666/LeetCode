/*
 * @Author: LetMeFly
 * @Date: 2024-12-11 23:20:41
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-11 23:21:46
 */
class Solution {
    public int semiOrderedPermutation(int[] nums) {
        int a = 0, b = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 1) {
                a = i;
            } else if (nums[i] == nums.length) {
                b = i;
            }
        }
        int ans = a + (nums.length - 1 - b);
        if (a > b) {
            ans--;
        }
        return ans;
    }
}