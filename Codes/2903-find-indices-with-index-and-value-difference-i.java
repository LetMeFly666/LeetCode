/*
 * @Author: LetMeFly
 * @Date: 2024-05-25 12:41:00
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-05-25 12:44:41
 */
class Solution {
    public int[] findIndices(int[] nums, int indexDifference, int valueDifference) {
        for (int i = 0; i < nums.length; i++) {
            for (int j = i; j < nums.length; j++) {
                if (j - i >= indexDifference && Math.abs(nums[i] - nums[j]) >= valueDifference) {
                    return new int[]{i, j};
                }
            }
        }
        return new int[]{-1, -1};
    }
}