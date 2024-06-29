/*
 * @Author: LetMeFly
 * @Date: 2024-06-29 17:14:25
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-29 17:16:38
 */
class Solution {
    public String removeTrailingZeros(String num) {
        int loc = num.length() - 1;
        while (num.charAt(loc) == '0') {
            loc--;
        }
        return num.substring(0, loc + 1);
    }
}