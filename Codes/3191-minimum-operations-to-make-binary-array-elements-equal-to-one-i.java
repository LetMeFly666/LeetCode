/*
 * @Author: LetMeFly
 * @Date: 2024-10-18 23:03:50
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-18 23:06:05
 */
class Solution {
    public int minOperations(int[] nums) {
        int ans = 0;
        for (int i = 0; i < nums.length - 2; i++) {
            if (nums[i] == 0) {
                ans++;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
            }
        }
        return (nums[nums.length - 1] & nums[nums.length - 2]) == 1 ? ans : -1;
    }
}