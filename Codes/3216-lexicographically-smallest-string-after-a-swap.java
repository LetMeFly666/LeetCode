/*
 * @Author: LetMeFly
 * @Date: 2024-10-30 12:34:00
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-30 12:42:18
 */
class Solution {
    public String getSmallestString(String s) {
        char[] tempS = s.toCharArray();
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i - 1) > s.charAt(i) && s.charAt(i - 1) % 2 == s.charAt(i) % 2) {
                char temp = s.charAt(i);
                tempS[i] = tempS[i - 1];
                tempS[i - 1] = temp;
                // return tempS.toString();  // 不可，不然"45320"会变成"[C@5010be6"
                return new String(tempS);
            }
        }
        return s;
    }
}