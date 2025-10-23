/*
 * @Author: LetMeFly
 * @Date: 2025-10-23 23:05:13
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-23 23:42:40
 */
class Solution {
    public boolean hasSameDigits(String s) {
        int[] a = new int[s.length()];
        for (int i = 0; i < s.length(); i++) {
            a[i] = (s.charAt(i) - '0');
        }
        while (a.length > 2) {
            int[] b = new int[a.length - 1];
            for (int i = 0; i < b.length; i++) {
                b[i] = (a[i] + a[i + 1]) % 10;
            }
            a = b;
        }
        return a[0] == a[1];
    }
}