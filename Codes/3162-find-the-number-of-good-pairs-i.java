/*
 * @Author: LetMeFly
 * @Date: 2024-10-10 12:21:19
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-10 12:21:30
 */
class Solution {
    public int numberOfPairs(int[] nums1, int[] nums2, int k) {
        int ans = 0;
        for (int n1 : nums1) {
            for (int n2 : nums2) {
                if (n1 % (n2 * k) == 0) {
                    ans++;
                }
            }
        }
        return ans;
    }
}