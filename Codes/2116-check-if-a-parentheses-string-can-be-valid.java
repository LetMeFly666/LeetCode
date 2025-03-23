/*
 * @Author: LetMeFly
 * @Date: 2025-03-23 10:52:22
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-23 10:53:49
 */
class Solution {
    public boolean canBeValid(String s, String locked) {
        int l = 0, r = 0;
        for (int i = 0; i < s.length(); i++) {
            if (locked[i] == '0') {
                l--;
                r++;
                if (l < 0) {
                    l = 1;
                }
            } else {
                if (s[i] == '(') {
                    l++;
                    r++;
                } else {
                    l--;
                    r--;
                    if (r < 0) {
                        return false;
                    }
                    if (l < 0) {
                        l = 1;
                    }
                }
            }
        }
        return l == 0;
    }
}