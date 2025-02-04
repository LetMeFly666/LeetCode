/*
 * @Author: LetMeFly
 * @Date: 2025-02-04 22:25:10
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-04 22:28:26
 */
class Solution {
    public int[] sortArrayByParityII(int[] nums) {
        for (int i = 0, j = 1; i < nums.length;) {
            if (nums[i] % 2 == 0) {
                i += 2;
            } else if (nums[j] % 2 != 0) {
                j += 2;
            } else {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i += 2;
                j += 2;
            }
        }
        return nums;
    }
}