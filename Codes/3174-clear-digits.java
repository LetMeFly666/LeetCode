/*
 * @Author: LetMeFly
 * @Date: 2024-09-05 09:31:08
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-09-05 13:06:54
 */
class Solution {
    public String clearDigits(String s) {
        StringBuilder ans = new StringBuilder();
        int cntDigit = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (Character.isDigit(s.charAt(i))) {
                cntDigit++;
            }
            else if (cntDigit > 0) {
                cntDigit--;
            }
            else {
                ans.append(s.charAt(i));
            }
        }
        ans.reverse();
        return ans.toString();
    }
}