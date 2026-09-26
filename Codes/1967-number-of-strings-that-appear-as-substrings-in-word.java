/*
 * @Author: LetMeFly
 * @Date: 2026-06-29 15:07:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-06-29 15:23:03
 */
class Solution {
    public int numOfStrings(String[] patterns, String word) {
        int ans = 0;
        for (String p : patterns) {
            if (word.contains(p)) {
                ans++;
            }
        }
        return ans;
    }
}
