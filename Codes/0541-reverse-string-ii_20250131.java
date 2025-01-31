/*
 * @Author: LetMeFly
 * @Date: 2025-01-31 12:11:33
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-31 12:16:13
 */
class Solution {
    private void reverse(char[] s, int l, int r) {  // [l, r]
        while (l < r) {
            char temp = s[l];
            s[l++] = s[r];
            s[r--] = temp;
        }
    }

    public String reverseStr(String s1, int k) {
        char[] s = s1.toCharArray();
        for (int l = 0; l < s.length; l += k * 2) {
            reverse(s, l, Math.min(l + k, s.length) - 1);
        }
        // return s.toString();  // 不可！
        return new String(s);
    }
}