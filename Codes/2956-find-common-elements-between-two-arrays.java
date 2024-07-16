/*
* @Author: LetMeFly
* @Date: 2024-07-16 23:28:41
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-16 23:30:58
*/
import java.util.HashSet;

class Solution {
    public int[] findIntersectionValues(int[] nums1, int[] nums2) {
        HashSet<Integer> s1 = new HashSet<>(), s2 = new HashSet<>();
        for (int t : nums1) {
            s1.add(t);
        }
        for (int t : nums2) {
            s2.add(t);
        }
        int[] ans = new int[2];
        for (int t : nums1) {
            ans[0] += s2.contains(t) ? 1 : 0;
        }
        for (int t : nums2) {
            ans[1] += s1.contains(t) ? 1 : 0;
        }
        return ans;
    }
}