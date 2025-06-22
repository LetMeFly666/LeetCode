/*
 * @Author: LetMeFly
 * @Date: 2025-06-22 12:43:34
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-22 21:04:09
 */
class Solution {
    public String[] divideString(String s, int k, char fill) {
        String[] ans = new String[(s.length() + k - 1) / k];
        for (int i = 0; i < s.length(); i += k) {
            if (s.length() - i < k) {
                ans[i / k] = s.substring(i) + String.valueOf(fill).repeat(k - (s.length() - i));
            } else {
                ans[i / k] = s.substring(i, i + k);
            }
        }
        return ans;
    }
}