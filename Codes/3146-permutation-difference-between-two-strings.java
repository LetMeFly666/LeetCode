/*
 * @Author: LetMeFly
 * @Date: 2024-08-24 12:26:11
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-08-24 12:26:12
 */
class Solution {
    public int findPermutationDifference(String s, String t) {
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            ans += Math.abs(i - t.indexOf(s.charAt(i)));
        }
        return ans;
    }
}