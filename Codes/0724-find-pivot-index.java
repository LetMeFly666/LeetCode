/*
 * @Author: LetMeFly
 * @Date: 2024-07-08 13:18:49
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-08 13:26:52
 */
class Solution {
    public int pivotIndex(int[] nums) {
        int sum = 0;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
        }
        int nowSum = 0;
        for (int i = 0; i < nums.length; i++) {
            if (sum - nums[i] == nowSum * 2) {
                return i;
            }
            nowSum += nums[i];
        }
        return -1;
    }
}