/*
 * @Author: LetMeFly
 * @Date: 2024-10-19 09:27:44
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-19 09:27:45
 */
class Solution {
    public int minOperations(int[] nums) {
        int ans = 0, original = 1;
        for (int t : nums) {
            if ((t ^ original) == 1) {
                ans++;
                original ^= 1;
            }
        }
        return ans;
    }
}