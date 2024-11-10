/*
 * @Author: LetMeFly
 * @Date: 2024-11-10 16:45:00
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-10 17:49:31
 */
class Solution {
    public int singleNonDuplicate(int[] nums) {
        int l = 0, r = nums.length - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] == nums[mid ^ 1]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return nums[l];
    }
}