/*
 * @Author: LetMeFly
 * @Date: 2024-09-24 18:49:53
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-09-24 18:52:53
 */
class Solution {
    public long maximumSubsequenceCount(String text, String pattern) {
        long ans = 0, cnt0 = 0, cnt1 = 0;
        for (char c : text.toCharArray()) {
            if (c == pattern.charAt(1)) {
                ans += cnt0;
                cnt1++;
            }
            if (c == pattern.charAt(0)) {
                cnt0++;
            }
        }
        return ans + Math.max(cnt0, cnt1);
    }
}