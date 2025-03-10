/*
 * @Author: LetMeFly
 * @Date: 2025-03-10 12:48:24
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-10 12:49:58
 */
class Solution {
    public int divisorSubstrings(int num, int k) {
        String s = String.valueOf(num);
        int ans = 0;
        for (int i = 0; i < s.length() - k + 1; i++) {
            int thisNum = Integer.parseInt(s.substring(i, i + k));
            if (thisNum > 0 && num % thisNum == 0) {
                ans++;
            }
        }
        return ans;
    }
}