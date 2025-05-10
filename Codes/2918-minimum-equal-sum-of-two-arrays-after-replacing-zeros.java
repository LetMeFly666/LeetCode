/*
 * @Author: LetMeFly
 * @Date: 2025-05-10 12:07:54
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-10 19:32:19
 */
class Solution {
    public long minSum(int[] nums1, int[] nums2) {
        long s1 = 0, s2 = 0;
        int c1 = 0, c2 = 0;
        for (int t : nums1) {
            s1 += t;
            if (t == 0) {
                c1++;
            }
        }
        for (int t : nums2) {
            s2 += t;
            if (t == 0) {
                c2++;
            }
        }
        if (s1 < s2 + c2 && c1 == 0 || s1 + c1 > s2 && c2 == 0) {
            return -1;
        }
        return Math.max(s1 + c1, s2 + c2);
    }
}