/*
 * @Author: LetMeFly
 * @Date: 2025-03-17 12:21:49
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-17 12:21:49
 */
class Solution {
    public int minSwaps(String s) {
        int zuoQianYou = 0, zuo = 0;
        for (char c : s.toCharArray()) {
            if (c == '[') {
                zuo++;
            } else {
                if (zuo > 0) {
                    zuo--;
                } else {
                    zuoQianYou++;
                }
            }
        }
        return (zuoQianYou + 1) / 2;
    }
}