/*
 * @Author: LetMeFly
 * @Date: 2025-07-15 23:15:03
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-15 23:35:42
 */
class Solution {
    private boolean isYuan(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    public boolean isValid(String word) {
        if (word.length() < 3) {
            return false;
        }
        boolean hasYuan = false, hasFu = false;
        for (char c : word.toCharArray()) {
            if ('A' <= c && c <= 'Z') {
                c += 32;
            }
            if ('a' <= c && c <= 'z') {
                if (isYuan(c)) {
                    hasYuan = true;
                } else {
                    hasFu = true;
                }
            } else if (c < '0' || c > '9') {
                return false;
            }
        }
        return hasYuan && hasFu;
    }
}