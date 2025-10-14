/*
 * @Author: LetMeFly
 * @Date: 2025-10-14 20:14:45
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-14 20:41:48
 */
// THIS IS RIGHT
class Solution {
    private boolean isOk(List<Integer> nums, int i, int k) {
        while (--k > 0) {
            if (nums.get(i) >= nums.get(++i)) {
                return false;
            }
        }
        return true;
    }

    public boolean hasIncreasingSubarrays(List<Integer> nums, int k) {
        for (int i = 0; i + 2 * k <= nums.size(); i++) {  // List没有length方法
            if (isOk(nums, i, k) && isOk(nums, i + k, k)) {
                return true;
            }
        }
        return false;
    }
}