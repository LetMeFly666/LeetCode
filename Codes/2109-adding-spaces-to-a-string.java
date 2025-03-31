/*
 * @Author: LetMeFly
 * @Date: 2025-03-31 14:37:11
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-31 14:44:41
 */
import java.lang.StringBuffer;

class Solution {
    public String addSpaces(String s, int[] spaces) {
        StringBuffer sb = new StringBuffer(s.length() + spaces.length);
        for (int i = 0, j = 0; i < s.length(); i++) {
            if (j < spaces.length && spaces[j] == i) {
                sb.append(' ');
                j++;
            }
            sb.append(s.charAt(i));
        }
        return sb.toString();
    }
}