/*
 * @Author: LetMeFly
 * @Date: 2025-01-01 18:51:17
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-01 18:52:45
 */
class Solution {
    public String convertDateToBinary(String date) {
        String[] a = date.split("-");
        for (int i = 0; i < a.length; i++) {
            a[i] = Integer.toBinaryString(Integer.parseInt(a[i]));
        }
        return String.join("-", a);
    }
}