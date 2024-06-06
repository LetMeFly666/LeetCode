/*
 * @Author: LetMeFly
 * @Date: 2024-06-06 22:41:50
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-06 22:43:17
 */
class Solution {
    public long minimumSteps(String s) {
        long ans = 0, times = 0;
        for (char c : s.toCharArray()) {
            if (c == '1') {
                times++;
            }
            else {
                ans += times;
            }
        }
        return ans;
    }
}