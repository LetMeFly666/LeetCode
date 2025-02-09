/*
 * @Author: LetMeFly
 * @Date: 2025-02-09 08:53:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-09 08:58:07
 */
class Solution {
    public int removeDuplicates(int[] nums) {
        int slow = 1;
        for (int fast = 2; fast < nums.length; fast++) {
            if (nums[fast] != nums[slow - 1]) {
                nums[++slow] = nums[fast];
            }
        }
        return Math.min(slow + 1, nums.length);
    }
}